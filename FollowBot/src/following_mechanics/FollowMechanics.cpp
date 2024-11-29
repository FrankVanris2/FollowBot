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
        if (rssiList.size() > 30) {
            mRSSITotal -= rssiList.back();
            rssiList.pop_back();
        }
        mRSSIAvg = mRSSITotal / (long) rssiList.size();

        Serial.print("FollowMechanics, RSSI Avg Value: ");
        Serial.println(mRSSIAvg);

        //if rssi > -50 robot will follow user
        //d = 10 ^ (A - mRSSI) / RmRSSI;
        

        //d = 10^(p-a)/10*B
        //where d is the distance from the current position to some beacon,
        // ρ is the RSSI at the current position,
        // a is the RSSI at some referenced distance (usually 1 m)
        //the path-loss exponent B is generally has a value in the range of 1.6–1.8 in an indoor environment
        //d = 10 ^ (A - mRSSI) / RmRSSI;
        //-50 came from checking iPhone hotspot 1m away

        unsigned d = static_cast<unsigned>(pow(10, (-50 - mRSSIAvg) / 10.0) * 1.8);
        
        if (mRSSIAvg > -50) {
            myMotors.setDirection("MOTOR_FORWARD");
        }
        if (mRSSIAvg < -50) {
            myMotors.setDirection("Stop");
        }
    }
}
