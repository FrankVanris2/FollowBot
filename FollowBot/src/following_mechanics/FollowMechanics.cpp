/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/

#include "FollowMechanics.h"
#include "followbot_client/FollowBotClient.h"
#include "objectavoidance&detection/ObjectDetection.h"
#include "states&types/MotorControlStates.h"
#include "motors/Motors.h"
#include <list>


// Interval
const int TENTH_SECOND = 100;

// Universal Object
FollowMechanics followMechanics;

// Constructor
FollowMechanics::FollowMechanics():  mRSSIAvg(0), mRSSITotal(0), previousMillis(0) {}


// Setup
void FollowMechanics::followMechanics_Setup() {

}

// Loop 
void FollowMechanics::followMechanics_Loop() { 
    if ((unsigned long) (millis() - previousMillis) >= TENTH_SECOND) {
        previousMillis = millis();

        followBotClient.checkRSSI();
        followMechanics.followMechanics_Averaging();

        myMotors.motorLoop();
        followMechanics_Algorithm();
    }
}


void FollowMechanics::followMechanics_Averaging() {
    //Add rssi value to list
        long followRSSI = followBotClient.getRSSI();
        rssiList.push_front(followRSSI);
        mRSSITotal += followRSSI;

        //if list is > 30 remove the last value 
        if (rssiList.size() > 30) {
            mRSSITotal -= rssiList.back();
            rssiList.pop_back();
        }
        mRSSIAvg = mRSSITotal / (long) rssiList.size();


        Serial.print("FollowMechanics, RSSI Avg Value: ");
        Serial.println(mRSSIAvg);
}

void FollowMechanics::followMechanics_Algorithm() {
    int distance1 = objectDetection.getDistance1();
    int distance2 = objectDetection.getDistance2();
    int distance3 = objectDetection.getDistance3();

    //including hysteresis functionality to prevent lag or delay
    const int DISTANCE_THRESHOLD_LOWER = 90; // 0.9 meters
    const int DISTANCE_THRESHOLD_UPPER = 110; // 1.1 meters

    // use the distance sensors as a reference to the robot's distance from the user
    if(distance1 < distance2 && distance1 < distance3) {
        myMotors.setDirection(MOTOR_LEFT);
    } else if(distance2 < distance1 && distance2 < distance3) {
        
        //if the user is to close the robot will stop at 1 meter distance 
        if(distance2 < DISTANCE_THRESHOLD_LOWER && mRSSIAvg < -60) {
            myMotors.setDirection(MOTOR_STOP);
        } else if (distance2 > DISTANCE_THRESHOLD_UPPER || mRSSIAvg >= -60) {
            myMotors.setDirection(MOTOR_FORWARD);
        }

    } else if(distance3 < distance2 && distance3 < distance1) {
        myMotors.setDirection(MOTOR_RIGHT);
    }
 
}


