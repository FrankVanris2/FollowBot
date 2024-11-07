from flask import Flask, request, send_file, jsonify, abort, make_response
from flask_cors import CORS
from handleRobotData import handleRobotData, getDirection, handleMovementData
import os

app = Flask(__name__)
CORS(app)  # Enable CORS


#Global data variables needed
temperature_data = None #Global variable to store temperature data
heatIndex_data = None #Global variable to store heat index data


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




    

