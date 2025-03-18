/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating the following mechanic between the user and the robot.
*/
#pragma once

#include <list>
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


const int GPS_FOLLOW_TIMEOUT = 100;

class FollowMechanics {
public:

    FollowMechanics();

    void followMechanics_Setup();
    void followMechanics_Loop();

private:
    unsigned long previousMillis;

    //list for RSSI Avg
    std::list<long> rssiList;

    long mRSSITotal;
    long mRSSIAvg;

    //drive mechanics
    void drive(float distance, float turn);

    void driveTo_Test_1(struct GeoLoc &loc, int timeout);
    void driveTo_Test_2(struct GeoLoc &loc, int timeout);

    //Mathematical stuff
    float geoDistance(struct GeoLoc &a, struct GeoLoc &b);
    float geoBearing(struct GeoLoc &a, struct GeoLoc &b);

    void followMechanics_Averaging();
    void followMechanics_Algorithm();
};

extern FollowMechanics followMechanics;