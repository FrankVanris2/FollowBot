/*
By: Frank Vanris
Date: 3/5/2025
Desc: Creating a gps class which allows me to send position data to the raspberry pi in order to let the user know where the robot is.
*/

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include "GPS.h"


//The TX pin is 1, and the RX pin is 0

//Singelton
GPS myGPS;

// The TinyGPS++ object
TinyGPSPlus gps;


GPS::GPS(): GPSBaud(9600) {
    //Constructor
}

void GPS::gps_setup() {
    Serial1.begin(GPSBaud);

    Serial.println(F("DeviceExample.ino"));
    Serial.println(F("A simple demonstration of TinyGPS++ with an attached GPS module"));
    Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
    Serial.println(F("by Mikal Hart"));
    Serial.println();
}


void GPS::gps_loop() {
    // This sketch displays information every time a new sentence is correctly encoded.
    while (Serial1.available() > 0) {
        if (gps.encode(Serial1.read()))
            displayInfo();
    }

    if (millis() > 5000 && gps.charsProcessed() < 10)
    {
        Serial.println(F("No GPS detected: check wiring."));
        while(true);
    }   
}

void GPS::displayInfo() {
    Serial.print(F("Location: ")); 
    if (gps.location.isValid())
    {
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), 6);
    }
    else
    {
        Serial.print(F("INVALID"));
    }
    Serial.println();
}

