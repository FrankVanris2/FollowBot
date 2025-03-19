/*
By: Frank Vanris
Date: 3/17/2025
Desc: using a compass to determine the robots position
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <QMC5883LCompass.h>
#include "Compass.h"
#include "states&types/MathematicalDefinitions.h"

const byte HEADING_OFFSET = -6; // Adjust this value based on your calibration


// Singelton
Compass compass;

QMC5883LCompass myCompass;

Compass::Compass(): isError(false) {
    // Constructor implementation
}

void Compass::compass_Setup() {
    myCompass.init();
    myCompass.setMagneticDeclination(15, 4);
}

void Compass::compass_loop() {
}

float Compass::geoHeading() {
    if (isError) {
        return 0.0;
    }
    myCompass.read();
    byte azimuth = myCompass.getAzimuth();
    byte bearing = myCompass.getBearing(azimuth);  
    bearing = (bearing + HEADING_OFFSET) % 12; // Adjust the bearing to the range of 0-11
    Serial.println(String("Bearing: ") + bearing);
    float headingDegrees = bearing * (360 / 12) - 180;

    return headingDegrees;
}