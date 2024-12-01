/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/

#include "FollowMechanics.h"
#include "followbot_client/FollowBotClient.h"
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
    }
}

void FollowMechanics::followMechanics_Averaging() {
    //Add rssi value to list
        long followRSSI = followBotClient.getRSSI();
        rssiList.push_front(followRSSI);
        mRSSITotal += followRSSI;

        //if list is > 5 remove the last value 
        if (rssiList.size() > 30) {
            mRSSITotal -= rssiList.back();
            rssiList.pop_back();
        }
        mRSSIAvg = mRSSITotal / (long) rssiList.size();

        Serial.print("FollowMechanics, RSSI Avg Value: ");
        Serial.println(mRSSIAvg);
}
