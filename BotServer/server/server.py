from flask import Flask, request, jsonify
from handleRobotData import handleRobotData, getDirection

app = Flask(__name__)

@app.get("/")
def getIndexHtml():
    with open('./index.html') as file:
        return file.read()

@app.get("/favicon.ico")
def getCrazyFace():
    with open('./images/crazyface.png', mode='rb') as file:
        return file.read()

@app.get("/<filename>")
def getTextFiles(filename):
    with open('./' + filename) as file:
        return file.read()

@app.get("/images/<filename>")
def getImageFiles(filename):
    with open('./images/' + filename, mode='rb') as file:
        return file.read()


@app.get("/api/getmove")
def getMove():
    return getDirection()

@app.post("/api/robotinfo")
def postRobotInfo():
    robotData = request.get_json()
    response_data = handleRobotData(robotData)
    return jsonify(response_data)
    

