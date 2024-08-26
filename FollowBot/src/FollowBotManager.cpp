/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: Creating a manager of all the methods and objects that will run in the main
* via the setup and loop
*/

#include "FollowBotManager.h"
#include "MotorControlStates.h"
#include "Motors.h"
#include "ObjectAvoidance.h"
#include "FollowBotClient.h"
//universal object
FollowBotManager followBotManager;

FollowBotManager::FollowBotManager(): mDirection(MOTOR_STOP) {
    
}


//the setup that will store the many objects that will set in the main
void FollowBotManager::followBotSetup() {
    // myMotors.motorSetup();
    // followBotClient.followBotClient_Setup();
    objectAvoidance.objectAvoidance_Setup();
}

//the loop that will store the many objects that will loop in the main
void FollowBotManager::followBotLoop() {
    // followBotClient.followBotClient_Loop();
    // myMotors.motorLoop();
    objectAvoidance.objectAvoidance_Loop();
}