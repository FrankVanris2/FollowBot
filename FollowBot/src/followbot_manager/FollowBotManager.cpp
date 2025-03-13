/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: Creating a manager of all the methods and objects that will run in the main
* via the setup and loop
*/


//NEEDED
#include "FollowBotManager.h"
#include "followbot_ui/FollowBotLCD.h"
#include "secrets/EEPROMStorage.h"
#include "followbot_client/FollowBotClient.h"
#include "ROS2_Serial/ROS2_Serial.h"
#include "states&types/MotorControlStates.h"
#include "motors/Motors.h"
#include "sensors/Gyroscope.h"
#include "gps/GPS.h"
#include "following_mechanics/FollowMechanics.h"

//CURRENTLY NOT NEEDED
//#include "objectavoidance&detection/ObjectAvoidance.h"
//#include "objectavoidance&detection/ObjectDetection.h"

//#include "sensors/TemperatureReader.h"



//universal object
FollowBotManager followBotManager;

FollowBotManager::FollowBotManager(): mIsDirty(false) {
    //mDirection(MOTOR_STOP)
}



//the setup that will store the many objects that will set in the main
void FollowBotManager::followBotSetup() {  
    eepromStorage.setup();  

    //REALLY NEEDED
    myLCDScreen.myLCDScreen_Setup();
    myMotors.motorSetup();
    followBotClient.followBotClient_Setup();
    gyroscope.gyroscope_Setup();
    myGPS.gps_setup();

    //NEEDED
    //followMechanics.followMechanics_Setup();
    
    //WORKING ON
    // objectAvoidance.objectAvoidance_Setup();
    // objectDetection.objectDetection_Setup();
    
    

}

void FollowBotManager::followBotLoop() {

    //REALLY NEEDED
    myLCDScreen.myLCDScreen_Loop();
    followBotClient.followBotClient_Loop();
    gyroscope.gyroscope_Loop();
    myGPS.gps_loop();
    ros2_serial.ros2_loop();
     
    //WORKING ON
    //followMechanics.followMechanics_Loop();

    //NOT NEEDED YET
    //objectDetection.objectDetection_Loop();
    

}


