'''
By: Frank Vanris
Date: 9/4/2024
Desc: Handles the robot data
'''
import random

movement = 'Stop'

def handleRobotData(robotData):
    print(f"here is the robot data: {robotData} ")

def handleMovementData(movementData):
    global movement
    print(f"here is the movement data: {movementData}")
    movement = movementData['direction']

def getDirection():
    global movement
    return movement
