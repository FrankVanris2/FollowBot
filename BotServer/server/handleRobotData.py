'''
By: Frank Vanris
Date: 9/4/2024
Desc: Handles the robot data
'''
import random

movement = 'stop'

def handleRobotData(robotData):
    print(f"here is the robot data: {robotData} ")

def handleMovementData(movementData):
    print(f"here is the movement data: {movementData}")
    direction = getDirection()
    if direction in movementData:
        movement = movementData[direction]
    else:
        print(f"Error: '{direction}' is not a valid direction")

def getDirection():
    return movement
