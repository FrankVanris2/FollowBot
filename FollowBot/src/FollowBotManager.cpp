/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: Creating a manager of all the methods and objects that will run in the main
* via the setup and loop
*/

#include "FollowBotManager.h"
#include "Motors.h"
//universal object
FollowBotManager followBotManager;

FollowBotManager::FollowBotManager() {
    
}


//the setup that will store the many objects that will set in the main
void FollowBotManager::followBotSetup() {
    Serial.begin(9600);
    myMotors.motorSetup();
}

//the loop that will store the many objects that will loop in the main
void FollowBotManager::followBotLoop() {
    myMotors.motorLoop();
}