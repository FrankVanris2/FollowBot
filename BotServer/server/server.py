from flask import Flask, request, send_file, jsonify, abort, make_response
from flask_login import LoginManager, login_user, logout_user, current_user, login_required
from flask_cors import CORS
import logging

from handleRobotData import handleRobotData, getDirection, handleMovementData


from db_server.user_model import UserModel
from db_server.followbot_model import FollowBotModel
from sessionUser import SessionUser

import os
import uuid
import hashlib
import traceback
import secrets
from werkzeug.security import check_password_hash

user_model = UserModel()
follow_bot_model = FollowBotModel()
login_manager = LoginManager()

app = Flask(__name__)
app.secret_key = secrets.token_hex(16)

login_manager.init_app(app)
CORS(app)  # Enable CORS

app.logger.setLevel(logging.INFO) # Set to the desired level

temperature_data = None   # Global variable to store temperature data
heatIndex_data = None     # Global variable to store heat index data


@login_manager.user_loader
def load_user(user_id):
    user_data = user_model.get_user(user_id)
    if user_data:
        pass
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
    logout_user()
    return jsonify({'message': 'Successfully logged out.'}), 200


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

        password = hashlib.sha256(password.encode()).hexdigest()
        user_id = str(uuid.uuid4())

        user_data = {
            'user_id': user_id,
            'username': username,
            'password': password,
            'email': email,
            'phone_number': phone_number,
            'business_id': business_id,
            'privacy_consent': privacy_consent,
            'follow_bots': []
        }

        response = user_model.create_user(**user_data)

        if response is None:
            return jsonify({'error': 'Failed to register user due to error in database'}), 500

        user = SessionUser(**user_data)
        login_user(user)

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
        this_bot = follow_bot_model.get_follow_bot(bot_id)

        if this_bot.functional_key != pending_functional_key:
            return jsonify({'error': 'This was not the correct functional key'}), 400

        user_id = data.get('user_id')

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



@app.get("/api/getmove")
def getMove():
    dir = getDirection()
    print(dir)
    response = make_response(dir)
    response.content_type = 'text/plain'
    return response
    #return dir

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




    

