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
#include "TemperatureReader.h"
#include "FollowBotClient.h"
#include "IrisClassifier.h"
//universal object
FollowBotManager followBotManager;

FollowBotManager::FollowBotManager(): mDirection(MOTOR_STOP), mIsDirty(false) {
    
}


//the setup that will store the many objects that will set in the main
void FollowBotManager::followBotSetup() {
    myMotors.motorSetup();
    followBotClient.followBotClient_Setup();
    temperatureReader.temperatureReader_Setup();
    objectAvoidance.objectAvoidance_Setup();
}

//the loop that will store the many objects that will loop in the main
void FollowBotManager::followBotLoop() {
    followBotClient.followBotClient_Loop();

    //Avoiding Obstacles
    objectAvoidance.objectAvoidance_Loop();
    
    //obtaining the Temperature
    temperatureReader.temperatureReader_Loop();

    // For motor movement
    myMotors.motorLoop();

    //Learning Model Testing
    /*
    float input[4] = {5.1, 3.5, 1.4, 0.2};
    Serial.print("Prediction: ");
    Serial.println(irisClassifier.predict(input));
    */
    
}