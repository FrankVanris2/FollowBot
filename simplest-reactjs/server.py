from flask import Flask

app = Flask(__name__)

@app.get("/")
def getIndexHtml():
    with open('./index.html') as file:
        return file.read()

@app.get("/favicon.ico")
def getCrazyFace():
    with open('./favicon.ico', mode='rb') as file:
        return file.read()

@app.get("/dist/main.min.js")
def getMainMinJs():
    with open('./dist/main.min.js') as file:
        return file.read()
