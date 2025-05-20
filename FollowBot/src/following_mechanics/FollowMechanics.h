/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating the following mechanic between the user and the robot.
*/
#pragma once

#include <list>
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

class FollowMechanics {
public:

    FollowMechanics();

    void followMechanics_Setup();
    void followMechanics_Loop();

private:
    unsigned long previousMillis;
    unsigned long previousMinute;

    //list for RSSI Avg
    std::list<int> rssiList;

    int mRSSITotal;
    int mRSSIAvg;
    long mMaxRSSI;
    long mMinRSSI;
    
    void followMechanics_Averaging();

    //drive mechanics
    void driveTo_Test_1();
    void driveTo_Test_WithHysteresis();

    void drive(float distance, float turn);

};

extern FollowMechanics followMechanics;