from flask import Flask, request, send_file, jsonify, abort, make_response
from flask_cors import CORS


from handleRobotData import handleRobotData, getDirection, handleMovementData

import os

#from db_server import user_model
import uuid
import hashlib

app = Flask(__name__)

CORS(app)  # Enable CORS


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


@app.get("/")
def get_index_html():
    try:
        with open('../index.html', encoding='utf-8') as file:
            return file.read()
    except FileNotFoundError:
        abort(404, description="File not found")

@app.get("/favicon.ico")
# dont get the why we need this function 
def get_favicon():
    try:
        return send_file('../images/crazyface.png', mimetype='image/png')
    except FileNotFoundError:
        abort(404, description="Favicon not found")

@app.get("/<filename>")
def get_text_files(filename):
    try:
        with open('../' + filename, encoding='utf-8') as file:
            return file.read()
    except FileNotFoundError:
        abort(404, description="File not found")
    except UnicodeDecodeError:
        abort(500, description="Error decoding file")

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




    

