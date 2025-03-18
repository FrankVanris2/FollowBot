/*
By: Frank Vanris
Date: 3/5/2025
Desc: Creating a GPS module that will be used in order to obtain the actual position of wheret the robot is.
*/

#pragma once
#include "states&types/FollowBotNavigation.h"
#define GPS_SIZE 2

enum GPSIndices {
    LAT = 0,
    LON
};

class GPS {

public:

    GPS();

    void gps_setup();
    void gps_loop();

    const GeoLoc& getRobotGPSData() { return robotGPSData;}

private:
    unsigned long interval;
    unsigned long previousMillis;   
    
    const uint32_t GPSBaud;
    GeoLoc robotGPSData;
};

extern GPS myGPS;