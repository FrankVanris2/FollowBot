import flask_login
from flask import Flask, request, send_file, jsonify, abort, make_response
from flask_login import LoginManager, login_user, logout_user, current_user, login_required
from flask_cors import CORS

from collections import deque
import logging

from handleRobotData import handleRobotData, getDirection, handleMovementData

from db_server.user_model import UserModel
from db_server.followbot_model import FollowBotModel
from sessionUser import SessionUser

import os
import uuid
import traceback
import secrets
from datetime import datetime
from decimal import Decimal
from werkzeug.security import check_password_hash, generate_password_hash

user_model = UserModel()
follow_bot_model = FollowBotModel()
login_manager = LoginManager()

app = Flask(__name__)
app.secret_key = secrets.token_hex(16)

login_manager.init_app(app)
CORS(app)  # Enable CORS

app.logger.setLevel(logging.INFO) # Set to the desired level

command_queue = deque()
temperature_data = None   # Global variable to store temperature data
heatIndex_data = None     # Global variable to store heat index data

MAPS_DIR = os.path.join(os.path.dirname(os.path.dirname(__file__)), 'dist', 'maps')
@app.route('/maps/<path:filename>')
def serve_maps(filename):
    return send_from_directory('MAPS_DIR', filename)

@login_manager.user_loader
def load_user(user_id):
    user_data = user_model.get_user(user_id)
    if user_data:
        return SessionUser(**user_data)
    return None


@app.post("/api/login")
def login():
    try:
        data = request.get_json()
        if not data:
            return jsonify({'error': 'No input provided'}), 400

        username = data.get('username')
        password = data.get('password')

        if not username or not password:
            return jsonify({'error': 'Missing required fields'}), 400

        user_data = user_model.get_user_by_username(username)
        if not user_data:
            return jsonify({'error': 'User not found'}), 404

        if not check_password_hash(user_data['password'], password):
            return jsonify({'error': 'Invalid credentials'}), 401

        user = SessionUser(**{
            "user_id": user_data["user_id"],
            "username": user_data["username"],
            "email": user_data["email"],
            "password": user_data["password"],
            "phone_number": user_data.get("phone_number", None),
            "business_id": user_data.get("business_id", None),
            "privacy_consent": user_data.get("privacy_consent", False),
            "follow_bots": user_data.get("follow_bots", [])
        })
        login_user(user)

        return jsonify({'message': 'Login successful', 'user_id': user_data['user_id']}), 200
    except KeyError as ke:
        print(f"KeyError during login: {ke}")
        return jsonify({'error': 'Invalid user data format'}), 500
    except Exception as e:
        print(f"Unexpected error during login: {traceback.format_exc()}")
        return jsonify({'error': 'An unexpected error occurred'}), 500


@app.post("/api/logout")
@login_required
def logout():
    try:
        logout_user()
        return jsonify({'message': 'Successfully logged out.'}), 200
    except Exception as e:
        print(f"Error during logout: {e}")
        return jsonify({'error': 'Logout failed'}), 500


@app.post("/api/signup")
def register_user():
    try:
        data = request.get_json()
        if not data:
            return jsonify({'error': 'No input provided'}), 400

        username = data.get('username')
        email = data.get('email')
        password = data.get('password')
        phone_number = data.get('phone_number')
        business_id = data.get('business_id')
        privacy_consent = data.get('privacy_consent')

        if not username or not email or not password:
            return jsonify({'error': 'Missing required fields'}), 400

        if user_model.get_user_by_email(email):
            return jsonify({'error': 'Email already registered'}), 400

        if user_model.get_user_by_username(username):
            return jsonify({'error': 'Username already in use'}), 400

        password = generate_password_hash(password)
        user_id = str(uuid.uuid4())[:8]

        response = user_model.create_user(**{
            "user_id": user_id,
            "username": username,
            "email": email,
            "password": password,
            "phone_number": phone_number or None,
            "business_id": business_id or None,
            "privacy_consent": privacy_consent or False,
            "follow_bots": []
        })

        if response is None:
            return jsonify({'error': 'Failed to register user due to error in database'}), 500

        return jsonify({'message': 'User registered successfully', 'user_id': user_id}), 200

    except Exception as e:
        print(f"Error in sign up: {e}")
        return jsonify({'error': 'An unexpected error occurred'}), 500


@app.post("/api/linkBot")
@login_required
def link_user_to_bot():
    try:
        data = request.get_json()

        pending_functional_key = data.get('functional_key')
        bot_id = data.get('bot_id')
        this_bot_dict = follow_bot_model.get_follow_bot(bot_id)

        if this_bot_dict.get('functional_key') != pending_functional_key:
            return jsonify({'error': 'This was not the correct functional key'}), 400

        user_id = flask_login.current_user.id

        fb_response = follow_bot_model.assign_user_to_bot(bot_id, user_id)
        user_response = user_model.add_bot(user_id, bot_id)

        if fb_response is None or user_response is None:
            return jsonify({'error': 'Failed to link the user to the FollowBot entry'}), 400

        return jsonify({'message': "Successfully linked the user to the FollowBot entry"}), 200

    except Exception as e:
        print(f"Error in accessing FollowBot entry: {e}")
        return jsonify({'error': 'An unexpected error occurred'}), 500


@app.post("/api/getBot")
@login_required
def get_bot():
    try:
        data = request.get_json()
        if not data:
            return jsonify({'error': 'No input provided'}), 400

        response = follow_bot_model.get_follow_bot(data.get('bot_id'))

        if response is None:
            return jsonify({'error': 'FollowBot entry does not exists.'}), 400

        if response:
            return jsonify({'message': 'This FollowBot exist.'}), 200

    except Exception as e:
        print(f"Error in accessing FollowBot entry: {e}")
        return jsonify({'error': 'An unexpected error occurred'}), 500


@app.get("/api/getUserBots")
@login_required
def get_user_bots():
    try:
        user_id = flask_login.current_user.id
        user_data = user_model.get_user(user_id)

        if not user_data:
            return jsonify({'error': 'User not found'}), 404

        follow_bots = user_data.get("follow_bots", [])
        return jsonify({'follow_bots': follow_bots}), 200

    except Exception as e:
        print(f"Error in retrieving user:{flask_login.current_user.id}'s FollowBot ids.")
        return jsonify({'error': 'An unexpected error occurred'}), 500


@app.get("/api/getBotLogs")
@login_required
def get_bot_logs():
    bot_id = request.args.get("bot_id")
    if not bot_id:
        return jsonify({"error": "Missing bot ID"}), 400

    bot_data = follow_bot_model.get_follow_bot(bot_id)
    if not bot_data:
        return jsonify({"error": "Bot not found"}), 404

    logs = bot_data.get("logs", [])
    return jsonify({"logs": logs}), 200


@app.post("/api/postBotLogs")
def update_logs():
    data = request.get_json()

    if not data:
        print("error invalid JSON")
        return jsonify({"error": "Invalid JSON payload"}), 400

    required_fields = ["botID", "temperature", "battery", "coordinates", "clock"]
    missing_fields = [field for field in required_fields if field not in data]
    if missing_fields:
        print(f"error missing fields: {', '.join(missing_fields)}")
        return jsonify({"error": f"Missing fields: {', '.join(missing_fields)}"}), 400

    clock_str = data["clock"]
    clock_datetime = datetime.strptime(clock_str, "%d/%m/%Y %H:%M:%S")

    date_str = clock_datetime.strftime("%d/%m/%Y")
    time_str = clock_datetime.strftime("%H:%M:%S")

    bot_id = str(data["botID"])

    new_log = {
        "temperature": Decimal(str(data["temperature"])),
        "last_location": [Decimal(str(coord)) for coord in data["coordinates"]],
        "battery": Decimal(str(data["battery"])),
        "date": date_str,
        "time": time_str
    }

    response = follow_bot_model.update_follow_bot_logs(bot_id, new_log)

    if response:
        print("good")
        return jsonify({"message": "Logs updated successfully"}), 200
    else:
        return jsonify({"error": "Failed to update logs"}), 500

# Pre: The Arduino board will send a consistent functional_key if IN_DATABASE is false.
# Post: A FollowBot entry is created in the database.
# Post: Returns a bot_id, which should be stored for future API functionalities.
@app.post("/api/createBotEntry")
def create_follow_bot_entry():
    try:
        functional_key = request.get_json().get("functional_key")
        if not functional_key:
            return jsonify({"error": "Missing functional key"}), 400

        bot_id = str(uuid.uuid4())[:8]

        response = follow_bot_model.create_follow_bot(**{
            'bot_id': bot_id,
            'functional_key': functional_key,
            'logs': [],
            'business_id': None,
            'assigned_user_id': None
        })

        if response is None:
            return jsonify({"error": "Failed to create the FollowBot entry"}), 500

        return jsonify({"bot_id": bot_id, "message": "FollowBot entry created successfully"}), 200

    except Exception as e:
        print(f"Error creating FollowBot entry: {e}")
        return jsonify({"error": "An unexpected error occurred"}), 500

@app.route('/api/postActionData', methods=['POST'])
def post_action_data():
    payload = request.get_json(force=True)
    data_string = payload.get('dataString')
    if not data_string:
        return jsonify({ 'error': 'Missing dataString' }), 400

    # Enqueue it (or overwrite a single “last command” variable, as you prefer)
    command_queue.append(data_string)
    return jsonify({ 'status': 'ok' }), 200

@app.route('/api/getActionData', methods=['GET'])
def get_action_data():
    if command_queue:
        # Pop oldest command
        next_cmd = command_queue.popleft()
        # Return as plain text
        return make_response(next_cmd, 200, { 'Content-Type': 'text/plain' })
    else:
        # Nothing to do
        return make_response('', 204)  # No Content

@app.get("/api/getTempInfo")
def getTemperatureInfo():
    if temperature_data is not None:
        return jsonify({"temperature": temperature_data})
    

@app.get("/api/getHeatIdxInfo")
def getHeatIdxInfo():
    if heatIndex_data is not None:
        return jsonify({"heatIndex": heatIndex_data})



@app.post("/api/robotinfo")
def postRobotInfo():
    global temperature_data
    global heatIndex_data

    robotData = request.get_json()
    handleRobotData(robotData)
    temperature_data = robotData.get('temperature')
    heatIndex_data = robotData.get('heatIndex')

    return "OK"

#post info for website->server->robot
@app.post("/api/postmovement") 
def postMovementInfo():
    movementInfoData = request.get_json()
    handleMovementData(movementInfoData)
    return "OK"

def get_index_html():
    try:
        with open('../index.html', encoding='utf-8') as file:
            return file.read()
    except FileNotFoundError:
        abort(404, description="File not found")


# Default page
@app.get("/")
def get_default_page():
    return get_index_html()

@app.get("/logo.png")
# dont get the why we need this function 
def get_favicon():
    try:
        return send_file('../images/logo.png', mimetype='image/png')
    except FileNotFoundError:
        abort(404, description="Favicon not found")

# Subpath pages
@app.get("/<subpage>")
def get_subpages(subpage):
    return get_index_html()

def get_text_file(filename):
    try:
        with open('../' + filename, encoding='utf-8') as file:
            return file.read()
    except FileNotFoundError:
        abort(404, description="File not found")
    except UnicodeDecodeError:
        abort(500, description="Error decoding file")

@app.get("/main.min.js")
def get_main_min_js():
    return get_text_file("main.min.js")

@app.get("/main.min.js.map")
def get_main_min_js_map():
    return get_text_file("main.min.js.map")


@app.get("/fonts/<filename>")
def get_fonts(filename):
    try:
        return send_file(os.path.join('../fonts/', filename), mimetype='font/ttf')
    except FileNotFoundError:
        abort(404, description="font file not found")

@app.get("/images/<filename>")
def get_image_files(filename):
    try:
        return send_file(os.path.join('../images/', filename), mimetype='image/jpeg')
    except FileNotFoundError:
        abort(404, description="Image file not found")






