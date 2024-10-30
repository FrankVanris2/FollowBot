/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/

#include "FollowMechanics.h"
#include "FollowBotClient.h"
#include "Motors.h"
#include <list>
#include "Arduino.h"


// Interval
const int TENTH_SECOND = 100;

// Universal Object
FollowMechanics followMechanics;

// Constructor
FollowMechanics::FollowMechanics():  mRSSIAvg(0), mRSSITotal(0), mPreviousMillisRSSI(0) {}


// Setup
void FollowMechanics::followMechanics_Setup() {

}

// Loop 
void FollowMechanics::followMechanics_Loop() {
    // TEST 1: I am trying to obtain the signal strength in order to obtain the distance by an average.
    unsigned long currentMillisForRSSI = millis(); 
    if ((unsigned long) (currentMillisForRSSI - mPreviousMillisRSSI) >= TENTH_SECOND) {
        mPreviousMillisRSSI = currentMillisForRSSI;
        //Add rssi value to list
        long followRSSI = followBotClient.getRSSI();
        rssiList.push_front(followRSSI);
        mRSSITotal += followRSSI;

        //if list is > 5 remove the last value 
        if (rssiList.size() > 5) {
            mRSSITotal -= rssiList.back();
            rssiList.pop_back();
        }
        mRSSIAvg = mRSSITotal / (long) rssiList.size();

        Serial.print("FollowMechanics, RSSI Avg Value: ");
        Serial.println(mRSSIAvg);

        //if rssi > -50 robot will follow user
        //d = 10 ^ (A - mRSSI) / RmRSSI;
        
        //if rssi < -50 robot will stop following user
        if (mRSSIAvg < -50) {
            myMotors.setDirection("Stop");
        }
    }
}
