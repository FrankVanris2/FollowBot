from flask import Flask

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
