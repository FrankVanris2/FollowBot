/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: Creating a manager of all the methods and objects that will run in the main
* via the setup and loop
*/

#include "FollowBotManager.h"
#include "Motors.h"
#include "FollowBotClient.h"
//universal object
FollowBotManager followBotManager;

FollowBotManager::FollowBotManager() {
    
}


//the setup that will store the many objects that will set in the main
void FollowBotManager::followBotSetup() {
    myMotors.motorSetup();
    followBotClient.followBotClient_Setup();
}

//the loop that will store the many objects that will loop in the main
void FollowBotManager::followBotLoop() {
    followBotClient.followBotClient_Loop();
    //myMotors.motorLoop();
}