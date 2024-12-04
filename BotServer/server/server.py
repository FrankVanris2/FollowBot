from flask import Flask, request, send_file, jsonify, abort, make_response
from flask_cors import CORS
import logging

from handleRobotData import handleRobotData, getDirection, handleMovementData

import os

from db_server.user_model import UserModel
import uuid
import hashlib

user_model = UserModel()
app = Flask(__name__)

CORS(app)  # Enable CORS

   
app.logger.setLevel(logging.INFO) # Set to the desired level

#Global data variables needed
temperature_data = None #Global variable to store temperature data
heatIndex_data = None #Global variable to store heat index data


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

        if not username or not email or not password:
            return jsonify({'error': 'Missing required fields'}), 400

        hashed_password = hashlib.sha256(password.encode()).hexdigest()
        user_id = str(uuid.uuid4())

        response = user_model.create_user(
            user_id=user_id,
            username=username,
            password=hashed_password,
            email=email,
            phone_number=phone_number,
            business_id=business_id
        )

        if response is None:
            return jsonify({'error': 'Failed to register user'}), 500

        return jsonify({'message': 'User registered successfully', 'user_id': user_id}), 200
    except Exception as e:
        print(f"Error in sign up: {e}")
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




    

