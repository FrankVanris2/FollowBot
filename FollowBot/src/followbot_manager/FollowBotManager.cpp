/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: Creating a manager of all the methods and objects that will run in the main
* via the setup and loop
*/

#include "FollowBotManager.h"
#include "states&types/MotorControlStates.h"
#include "motors/Motors.h"
#include "objectavoidance&detection/ObjectAvoidance.h"
#include "sensors/TemperatureReader.h"
#include "followbot_client/FollowBotClient.h"
#include "following_mechanics/FollowMechanics.h"
#include "ROS2_Testing/ros2Testing.h"

//testing currently
#include <ros.h>
#include <std_msgs/String.h>

//universal object
FollowBotManager followBotManager;

// Ros testing code
ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

FollowBotManager::FollowBotManager(): mIsDirty(false) {
    //mDirection(MOTOR_STOP)
}


//the setup that will store the many objects that will set in the main
void FollowBotManager::followBotSetup() {
    myMotors.motorSetup();
    followBotClient.followBotClient_Setup();
    temperatureReader.temperatureReader_Setup();
    objectAvoidance.objectAvoidance_Setup();
    //Serial.println("Finished Setup");

}

//the loop that will store the many objects that will loop in the main
void FollowBotManager::followBotLoop() {

    //ROS2 Testing:
    //ros2_TestingObj.ros2_loop();

    followBotClient.followBotClient_Loop();

    //Avoiding Obstacles
    //objectAvoidance.objectAvoidance_Loop();
    //if(objectAvoidance.getDistance1() <= 20 || objectAvoidance.getDistance2() <= 20) {
        //myMotors.motorStop();
    //}
    
    //obtaining the Temperature
    temperatureReader.temperatureReader_Loop();
    followMechanics.followMechanics_Loop();
    // For motor movement
    myMotors.motorLoop();
    
}