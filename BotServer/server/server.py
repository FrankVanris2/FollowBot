from flask import Flask
import random

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

@app.get("/move")
def getMove():
    # List of testing movements the robot will conduct
    movementList = ['Forward', 'Backward', 'Left', 'Right', 'Stop']

    # Selecting random item from list
    selected_item = random.choice(movementList)

    return selected_item

@app.post("/temp")
def postTemp():
    temperature = request.form.get('tempearture')
    if temperature:
        print(f"Received temperature: {temperature}°C")
        return "Temperature received", 200
    else:
        return "No temperature data", 400
    

