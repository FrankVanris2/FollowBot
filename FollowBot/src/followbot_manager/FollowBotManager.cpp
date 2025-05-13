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
#include "sensors/Encoders.h"
#include "sensors/BatteryReader.h"

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

    followBotBluetooth.setup();
    eepromStorage.setup();  
    myLCDScreen.myLCDScreen_Setup();
    followBotClient.followBotClient_Setup();  
    myMotors.motorSetup();
    myGPS.gps_setup();

    //Testing
    encoders.setupEncoders();
  
    // ROS2 specific:
    gyroscope.gyroscope_Setup();

}

void FollowBotManager::followBotLoop() {
    followBotBluetooth.loop();
    batteryReader.batteryReaderLoop();
    myLCDScreen.myLCDScreen_Loop();
    followBotClient.followBotClient_Loop(); 
    myGPS.gps_loop(); 
    if(mCurrentControl == IDLE) {
        myMotors.setDirection(MOTOR_STOP);
    } else if (mCurrentControl == ROBOT) {

    } 
    myMotors.motorLoop();

    // Testing
    encoders.loopEncoders();

    // //ROS2 Specific
    gyroscope.gyroscope_Loop();
    ros2_serial.ros2_loop();
    
}


