/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/


#include <list>
#include <Wire.h>
#include <math.h>

#include "FollowMechanics.h"
#include "followbot_client/FollowBotClient.h"

#include "states&types/MotorControlStates.h"
#include "states&types/FollowBotNavigation.h"
#include "states&types/MathematicalDefinitions.h"

#include "followbot_client/FollowBotBluetooth.h"
#include "motors/Motors.h"
#include "gps/GPS.h"

//#include "objectavoidance&detection/ObjectDetection.h"

// Interval
const int TENTH_SECOND = 100; // ms


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
        
        Serial.println(String("Bluetooth is enabled: ") + followBotBluetooth.isEnabled());
        if (followBotBluetooth.isEnabled()) {
            followMechanics_Averaging(); // Get and average RSSI
            Serial.println(String("FollowMechanics_Loop(), RSSI Value: ") + mRSSIAvg);
            //if (mRSSIAvg < -50) {
                //driveTo_Test_1();
                //driveTo_Test_2();
            //} else {
             //   myMotors.stopMoving();
            //}
            
            //driveTo_Test_2();

            if (mRSSIAvg < -50) {
                Serial.println("Moving Forwards");
                myMotors.moveForward();
            } else {
                Serial.println("Stopping Motors");
                myMotors.stopMoving();
            }
        }
    }
}

void FollowMechanics::followMechanics_Averaging() {
    int followRSSI = followBotBluetooth.getRSSI();
    rssiList.push_front(followRSSI);
    mRSSITotal += followRSSI;

    if (rssiList.size() > 50) {
        mRSSITotal -= rssiList.back();
        rssiList.pop_back();
    }
    mRSSIAvg = mRSSITotal / (int) rssiList.size();

    Serial.print("FollowMechanics, RSSI Avg Value: ");
    Serial.println(mRSSIAvg);
}






