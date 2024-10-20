/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/

#include "FollowMechanics.h"
#include "FollowBotClient.h"
#include <list>
#include "Arduino.h"


// Universal Object
FollowMechanics followMechanics;

// Constructor
FollowMechanics::FollowMechanics() {}


// Setup
void FollowMechanics::followMechanics_Setup() {

}

// Loop 
void FollowMechanics::followMechanics_Loop() {
    // TEST 1: I am trying to obtain the signal strength in order to obtain the distance by an average.
    
    long followRSSI = followBotClient.getRSSI();
    //input rssi value to list
    rssiList.push_front(followRSSI);


    //if list size is  < to 5 sum up the total nums in the list and divide by size
    if (rssiList.size() < 5) {
        mTotal += followRSSI;
        mRSSIAvg = mTotal / rssiList.size();
    }
    //if list is >= 5, sum up the total nums in the list and divide by 5
    else {   
        mTotal -= rssiList.back();
        rssiList.pop_back();
        mTotal += followRSSI;
        mRSSIAvg = mTotal / 5; // always divide by 5 since the list should always have 5
    }
    


    Serial.print("RSSI Value: ");
    Serial.println(mRSSIAvg);
}
