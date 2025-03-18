/*
By: Frank Vanris
Date: 3/17/2025
Desc: using a compass to determine the robots position
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

#include "Compass.h"


Adafruit_HMC5883_Unified myCompass = Adafruit_HMC5883_Unified(12345);

// Singelton
Compass compass;

Compass::Compass() {
    // Constructor implementation
}

Compass::compass_Setup() {

}