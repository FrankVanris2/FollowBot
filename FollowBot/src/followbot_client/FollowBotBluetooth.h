/*
By: Frank Vanris
Date: 3/16/2025
Desc: Creating a bluetooth connection for my arduino uno rev4 board.
*/

#pragma once
#include "states&types/FollowBotNavigation.h"

class FollowBotBluetooth {

public:
    FollowBotBluetooth();
    void setup();
    void loop();

    void setMobileGPSData(float lat, float lon) {
        mobileGPSData.lat = lat;
        mobileGPSData.lon = lon;
    }
    
    const GeoLoc& getMobileGPSData() { return mobileGPSData; }
private:
    bool isError;
    GeoLoc mobileGPSData;
};

extern FollowBotBluetooth followBotBluetooth; // Declare the singleton instance