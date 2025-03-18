/*
By: Frank Vanris
Date: 3/17/2025
Desc: using a compass to determine the robots position
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

#include "Compass.h"
#include "states&types/MathematicalDefinitions.h"


Adafruit_HMC5883_Unified myCompass = Adafruit_HMC5883_Unified(12345);

// Singelton
Compass compass;

Compass::Compass(): isError(false) {
    // Constructor implementation
}

void Compass::compass_Setup() {
    if(!myCompass.begin()) {
        Serial.println("HMC5883 was not detected, check wiring");
        isError = true;
    } else {
        Serial.println("HMC5883 detected");
        displayCompassDetails();
    }
}

void Compass::displayCompassDetails(void) {
    sensor_t sensor;
    myCompass.getSensor(&sensor);
    Serial.println("------------------------------------");
    Serial.println(String("Sensor: ") + sensor.name);
    Serial.println(String("Driver Ver: ") + sensor.version);
    Serial.println(String("Unique ID: ") + sensor.sensor_id);
    Serial.println(String("Max Value: ") + sensor.max_value + " uT");
    Serial.println(String("Min Value: ") + sensor.min_value + " uT");
    Serial.println(String("Resolution: ") + sensor.resolution + " uT");
    Serial.println("------------------------------------"); 
    Serial.println("");
}

float Compass::geoHeading() {
    if (isError) {
        return 0.0;
    }

    sensors_event_t event; 
    myCompass.getEvent(&event);

    // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
    // Calculate heading when the magnetometer is level, then correct for signs of axis.
    float heading = atan2(event.magnetic.y, event.magnetic.x);

    // Offset
    heading -= DECLINATION_ANGLE;
    heading -= COMPASS_OFFSET;
    
    // Correct for when signs are reversed.
    if(heading < 0)
        heading += 2*PI;
        
    // Check for wrap due to addition of declination.
    if(heading > 2*PI)
        heading -= 2*PI;
    
    // Convert radians to degrees for readability.
    float headingDegrees = heading * 180/M_PI; 

    // Map to -180 - 180
    while (headingDegrees < -180) headingDegrees += 360;
    while (headingDegrees >  180) headingDegrees -= 360;

    return headingDegrees;
}