'''
By: Frank Vanris
Date: 9/4/2024
Desc: Handles the robot data
'''

def handleRobotData(robotData):
    print(f"here is the robot data: {robotData} ")

    movementList = ['Forward', 'Backward', 'Left', 'Right', 'Stop']

    # Selecting random item from list
    selected_item = random.choice(movementList)

    return selected_item