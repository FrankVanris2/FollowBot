/*
By: Frank Vanris
Date: 11/27/2024
Desc: Creating a testing env for ROS2 in order to determine if there is communication between both devices
*/

#include <ArduinoJson.h>
#include <Arduino.h>

#include "ROS2_Serial.h"
#include "sensors/Gyroscope.h"
#include "gps/GPS.h"


//Singelton
ROS2_Serial ros2_serial;

ROS2_Serial::ROS2_Serial(): interval(TEST_INTERVAL), previousMillis(0) {}

void ROS2_Serial::ros2_loop() {
    if ((millis() - previousMillis) >= interval) {
        previousMillis = millis();
        ros2SerialData();
        dataToSerial();
    } 
}

void ROS2_Serial::ros2SerialData() {
    if(Serial.available() > 0) {
        String message = Serial.readStringUntil('\n');
        //to do, put this into a logger file
        Serial.print("Received message: ");
        Serial.print(message);
    } else {
        Serial.println("Pi is not sending any data");
    }
}

void ROS2_Serial::dataToSerial() {
    imuDataDoc();
    gpsDataDoc();
}

void ROS2_Serial::imuDataDoc() {
    const double* gyroData = gyroscope.getGyroData();

    StaticJsonDocument<256> imuDoc; 

    imuDoc["sensor_type"] = "imu";
    JsonObject imuData = imuDoc.createNestedObject("data");
    imuData["ax"] = gyroData[AX];
    imuData["ay"] = gyroData[AY];
    imuData["az"] = gyroData[AZ];
    imuData["gx"] = gyroData[GX];
    imuData["gy"] = gyroData[GY];
    imuData["gz"] = gyroData[GZ];

    //Serialize the JSON object to a string and send it over Serial
    serializeJson(imuDoc, Serial);
    Serial.println();
}

void ROS2_Serial::gpsDataDoc() {
    const double* gpsData = myGPS.getGPSData();

    StaticJsonDocument<256> gpsDoc; 

    gpsDoc["sensor_type"] = "gps";
    JsonObject gpsDataDoc = gpsDoc.createNestedObject("data");
    gpsDataDoc["latitude"] = gpsData[LAT];
    gpsDataDoc["longitude"] = gpsData[LON];

    serializeJson(gpsDoc, Serial);
    Serial.println();
}