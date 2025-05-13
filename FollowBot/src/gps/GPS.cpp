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


void GPS::gps_loop() {
    // This sketch displays information every time a new sentence is correctly encoded.
    if ((millis() - previousMillis) >= interval) {
        previousMillis = millis();

        while (Serial1.available() > 0) {
            if (gps.encode(Serial1.read())) {
                if(gps.location.isValid()) {
                    robotGPSData.lat = gps.location.lat();
                    robotGPSData.lon = gps.location.lng();
                    followBotManager.setGPSData(gps.location.lat(), gps.location.lng());
                    //Serial.println(String("Latitude: ") + robotGPSData.lat + ", Longitude: " + robotGPSData.lon);
                } else {
                    Serial.println("GPS is not valid. Keeping previous coordinates");
                }

                if(gps.date.isValid() && gps.time.isValid()) {
                    followBotManager.setClock(gps.date.day(), gps.date.month(), gps.date.year(), gps.time.hour(), gps.time.minute(), gps.time.second());
                } else {
                    Serial.println("GPS date/time is not valid. Keeping previous time");
                }
            }
        }

        if (millis() > 5000 && gps.charsProcessed() < 10) {
            Serial.println(F("No GPS detected: check wiring."));
            robotGPSData.lat = 0.0;
            robotGPSData.lon = 0.0;
        }   
    }
}


