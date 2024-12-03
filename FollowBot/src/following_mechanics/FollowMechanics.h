/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating the following mechanic between the user and the robot.
*/

#include <list>

#pragma once

class FollowMechanics {
public:

    FollowMechanics();

    void followMechanics_Setup();
    void followMechanics_Loop();

    void followMechanics_Averaging();

private:
    unsigned long previousMillis;

    //list for RSSI Avg
    std::list<long> rssiList;

    long mRSSITotal;
    long mRSSIAvg;
};

extern FollowMechanics followMechanics;