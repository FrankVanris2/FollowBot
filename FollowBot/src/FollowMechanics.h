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

private:

    // Math Values
    long mA;

    int mTotal;

    int mRSSIAvg;

    //list for RSSI Avg
    std::list<int> rssiList;
};

extern FollowMechanics followMechanics;