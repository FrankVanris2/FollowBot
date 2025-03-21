/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/


#include <list>

#include "FollowMechanics.h"
#include "followbot_client/FollowBotClient.h"
#include "states&types/MotorControlStates.h"
#include "motors/Motors.h"

//#include "objectavoidance&detection/ObjectDetection.h"




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

        followMechanics_Averaging(); // Get and average RSSI
        followMechanics_Algorithm(); // Use RSSI to decide robot movement
        myMotors.motorLoop();
        
    }
}


void FollowMechanics::followMechanics_Averaging() { 
    long followRSSI = followBotClient.getRSSI();
    rssiList.push_front(followRSSI);
    mRSSITotal += followRSSI;

    if (rssiList.size() > 10) {
        mRSSITotal -= rssiList.back();
        rssiList.pop_back();
    }
    mRSSIAvg = mRSSITotal / (long) rssiList.size();
    
    
    Serial.print("FollowMechanics, RSSI Avg Value: ");
    Serial.println(mRSSIAvg);      
}

void FollowMechanics::followMechanics_Algorithm() {
    if (mRSSIAvg > -50) { // Strong signal -close proximity
        Serial.println("Stopping - Too close to user");
        myMotors.setDirection(MOTOR_STOP);
    } else if (mRSSIAvg < -55) { // Weak signal - far proximity
        Serial.println("Following User (Going Forward)");
        myMotors.setDirection(MOTOR_FORWARD);
    } 
}


