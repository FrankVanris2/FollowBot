/*
By: Frank Vanris
Date: 3/5/2025
Desc: Creating a gps class which allows me to send position data to the raspberry pi in order to let the user know where the robot is.
*/

#include <TinyGPS++.h>
#include "GPS.h"


//The TX pin is 1, and the RX pin is 0

//Singelton
GPS myGPS;

// The TinyGPS++ object
TinyGPSPlus gps;


GPS::GPS(): GPSBaud(9600), interval(3000), previousMillis(0) {
    gpsData[LAT] = 0.0;
    gpsData[LON] = 0.0;
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
                    setGPS(gps.location.lat(), gps.location.lng());
                } else {
                    Serial.println("GPS is not valid. Keeping previous coordinates");
                }
            }
        }

        if (millis() > 5000 && gps.charsProcessed() < 10) {
            Serial.println(F("No GPS detected: check wiring."));
            setGPS(0, 0);
        }   
    }
}


