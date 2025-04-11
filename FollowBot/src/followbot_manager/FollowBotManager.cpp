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
#include "followbot_client/FollowBotBluetooth.h"

#include "ROS2_Serial/ROS2_Serial.h"
#include "states&types/MotorControlStates.h"
#include "motors/Motors.h"

#include "sensors/Gyroscope.h"
#include "sensors/Compass.h"
#include "sensors/Encoders.h"

#include "gps/GPS.h"
#include "following_mechanics/FollowMechanics.h"

//CURRENTLY NOT NEEDED
//#include "objectavoidance&detection/ObjectAvoidance.h"
//#include "objectavoidance&detection/ObjectDetection.h"

//#include "sensors/TemperatureReader.h"



//universal object
FollowBotManager followBotManager;

FollowBotManager::FollowBotManager(): mIsDirty(false), mCurrentControl(ROBOT){
    //mDirection(MOTOR_STOP)
}



//the setup that will store the many objects that will set in the main

void FollowBotManager::followBotSetup() { 
    //Following Mechanics setup
    // myMotors.motorSetup();
    // compass.compass_Setup();
    // myGPS.gps_setup();
    //followBotBluetooth.setup();

    //Server Setup
    // eepromStorage.setup();  
    // myLCDScreen.myLCDScreen_Setup();
    // myMotors.motorSetup();
    // followBotClient.followBotClient_Setup();  
    // myGPS.gps_setup();

    //Testing
    encoders.setupEncoders();

    
    //ROS2 specific:
    //gyroscope.gyroscope_Setup();

    //DELAYED
    // temperatureReader.temperatureReader_Setup();
    // objectAvoidance.objectAvoidance_Setup();
    // objectDetection.objectDetection_Setup();
    
    

}

void FollowBotManager::followBotLoop() {
    //Following Mechanics loop setup
    // myGPS.gps_loop();
    // followMechanics.followMechanics_Loop();
    // compass.compass_loop();
    //followBotBluetooth.loop();

    //Server Setup
    // myLCDScreen.myLCDScreen_Loop();
    // followBotClient.followBotClient_Loop(); 
    // myGPS.gps_loop(); 
    // if (mCurrentControl == ROBOT) {
    //     followMechanics.followMechanics_Loop();
    // }
    // myMotors.motorLoop();

    // Testing
    encoders.loopEncoders();

    //ROS2 Specific
    //gyroscope.gyroscope_Loop();
    //ros2_serial.ros2_loop();
    
    //DELAYED
    //temperatureReader.temperatureReader_Loop();
    //objectDetection.objectDetection_Loop();
}


