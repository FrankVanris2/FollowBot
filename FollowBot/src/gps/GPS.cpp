/*
By: Frank Vanris
Date: 3/5/2025
Desc: Creating a gps class which allows me to send position data to the raspberry pi in order to let the user know where the robot is.
*/

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#include "followbot_manager/FollowBotManager.h"
#include "GPS.h"
#include "states&types/FollowBotNavigation.h"

//The TX pin is 1, and the RX pin is 0
const int FIVE_SECONDS = 5000; // 5 seconds

//Singelton
GPS myGPS;

// The TinyGPS++ object
TinyGPSPlus gps;


GPS::GPS(): GPSBaud(9600), interval(5000), previousMillis(0) {
    robotGPSData.lat = 0.0;
    robotGPSData.lon = 0.0;
}

void GPS::gps_setup() {
    Serial1.begin(GPSBaud);
}

/**
 * Main GPS processing loop
 * Reads data from GPS module at specified intervals
 * Updates position and time information when valid
 */
void GPS::gps_loop() {
    unsigned long currentMillis = millis();

    // This sketch displays information every time a new sentence is correctly encoded.
    if ((currentMillis - previousMillis) < interval) {
        return; // Exit early
    }

    previousMillis = currentMillis;


    // Check if the GPS module is properly connected
    if (currentMillis > FIVE_SECONDS && gps.charsProcessed() < 10) {
        // Only print error once per interval rather than continuously
        Serial.println(F("No GPS detected: check wiring."));
        return; // Exit early if GPS hardware isn't responding
    } 

    // Process al available GPS data
    bool hasNewData = false;


    while (Serial1.available() > 0) {
        if (gps.encode(Serial1.read())) {
            Serial.println(F("GPS data received"));
            hasNewData = true;
        }
    }

    // Only continue processing if we have new data
    if (!hasNewData) {
        return; // Exit early if no new GPS sentences were processed
    }
    
    // Check if location data is valid
    if (gps.location.isValid()) {
        // Update robot's position data
        if (gps.location.lat() != 0.0 && gps.location.lng() != 0.0) {
            robotGPSData.lat = gps.location.lat();
            robotGPSData.lon = gps.location.lng();

            // Update manager with new position
            followBotManager.setGPSData(robotGPSData.lat, robotGPSData.lon);

            // Uncomment for debugging
            // Serial.println(String("Latitude: ") + robotGPSData.lat + ", Longitude: " + robotGPSData.lon);

        } else {
            // Only print error once per interval
            Serial.println("GPS location is not valid. Keeping previous coordinates.");
            // No need to update coordinates - keep previous values
        }
    }

    // PERCHANCE WE CAN USE...MAYBE
    // Check if time data is valid
    // if (gps.date.isValid() && gps.time.isValid()) {
    //     // Update system time from GPS
    //     followBotManager.setClock(
    //         gps.date.day(),
    //         gps.date.month(), 
    //         gps.date.year(),
    //         gps.time.hour(), 
    //         gps.time.minute(), 
    //         gps.time.second()
    //     );
    // } else {
    //     // Only print error once per interval
    //     Serial.println("GPS time is not valid. Keeping previous time.");
    // }
}


