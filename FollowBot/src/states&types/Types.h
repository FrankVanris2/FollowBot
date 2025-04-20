/*
* By: Frank Vanris
* Date: 9/4/2024
* Desc: Creating generic types for different data
*/

#pragma once
#include <Arduino.h>

#include "config.h"

struct OutputData {
    int mBotID;
    float mTemperature;
    String mClock;
    double mCoordinates[GPS_COORDS];
};