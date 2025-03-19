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

    //list for RSSI Avg
    std::list<int> rssiList;

    int mRSSITotal;
    int mRSSIAvg;

    void followMechanics_Averaging();

    //drive mechanics
    void driveTo_Test_1();
    void driveTo_Test_2();

    void drive(float distance, float turn);

    //Mathematical stuff
    float geoDistance(struct GeoLoc &a, struct GeoLoc &b);
    float geoBearing(struct GeoLoc &a, struct GeoLoc &b);
};

extern FollowMechanics followMechanics;