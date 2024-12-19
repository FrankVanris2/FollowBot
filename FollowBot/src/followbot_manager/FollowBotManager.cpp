/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: Creating a manager of all the methods and objects that will run in the main
* via the setup and loop
*/

#include "FollowBotManager.h"
#include "states&types/MotorControlStates.h"
#include "motors/Motors.h"
//#include "objectavoidance&detection/ObjectAvoidance.h"
#include "sensors/TemperatureReader.h"
#include "followbot_client/FollowBotClient.h"
#include "following_mechanics/FollowMechanics.h"
#include "followbot_ui/FollowBotLCD.h"
//#include "ROS2_Testing/ros2Testing.h"


//universal object
FollowBotManager followBotManager;

FollowBotManager::FollowBotManager(): mIsDirty(false) {
    //mDirection(MOTOR_STOP)
}



//the setup that will store the many objects that will set in the main
void FollowBotManager::followBotSetup() {
    //myMotors.motorSetup();
    //followBotClient.followBotClient_Setup();
    //temperatureReader.temperatureReader_Setup();
    //objectAvoidance.objectAvoidance_Setup();

    //Screen Testing
    myLCDScreen.printHello();

}

void FollowBotManager::followBotLoop() {
    //ROS2 Testing:
    //ros2_TestingObj.ros2_loop();
    
    //temperatureReader.temperatureReader_Loop();
    //followBotClient.followBotClient_Loop();
    //followMechanics.followMechanics_Loop();

}


