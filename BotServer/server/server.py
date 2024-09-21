from flask import Flask, request, send_file, jsonify, abort
from flask_cors import CORS
from handleRobotData import handleRobotData, getDirection, handleMovementData
import os

app = Flask(__name__)
CORS(app)  # Enable CORS

@app.get("/")
def get_index_html():
    try:
        with open('./index.html', encoding='utf-8') as file:
            return file.read()
    except FileNotFoundError:
        abort(404, description="File not found")

@app.get("/favicon.ico")
# dont get the why we need this function 
def get_favicon():
    try:
        return send_file('./images/crazyface.png', mimetype='image/png')
    except FileNotFoundError:
        abort(404, description="Favicon not found")

@app.get("/<filename>")
def get_text_files(filename):
    try:
        with open('./' + filename, encoding='utf-8') as file:
            return file.read()
    except FileNotFoundError:
        abort(404, description="File not found")
    except UnicodeDecodeError:
        abort(500, description="Error decoding file")

@app.get("/images/<filename>")
def get_image_files(filename):
    try:
        return send_file(os.path.join('./images/', filename), mimetype='image/jpeg')
    except FileNotFoundError:
        abort(404, description="Image file not found")


@app.get("/api/getmove")
def getMove():
    return getDirection()

@app.post("/api/robotinfo")
def postRobotInfo():
    robotData = request.get_json()
    handleRobotData(robotData)
    return "OK"

#post info for website->server->robot
@app.post("/api/postmovement") 
def postMovementInfo():
    movementInfoData = request.get_json()
    handleMovementData(movementInfoData)
    return "OK"

from flask import Flask, send_file, jsonify, abort
from flask_cors import CORS
import random
import os

app = Flask(__name__)
CORS(app)  # Enable CORS


def extractTemperature(robotData):
    try:
        with open('robot_data.json', 'r') as json_file:
            data = json.load(json_file)

        temperature = data.get('temperature')
        heat_index = data.get('heat_index')
        
        # Return the relevant values as a JSON response
        response = {
            "received_robot_data": robotData,
            "temperature": temperature,
            "heat_index": heat_index
        }
        return jsonify(response)
    
    except FileNotFoundError:
        return jsonify({"error": "JSON file not found"}), 404
    except Exception as e:
        return jsonify({"error": str(e)}), 500
        




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
        return send_file('../src/crazyface.png', mimetype='image/png')
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

@app.get("/move")
def get_move():
    # will add Stop again in future
    movement_list = ['Forward', 'Backward', 'Left', 'Right','Stop']
    selected_item = random.choice(movement_list)
    return jsonify({'movement': selected_item})


@app.post("/exchangeInfo")
def postTemp():
    robotData = request.json()
    extractdata = extractTemperature(robotData)


    return handleRobotData(extractdata)




    

