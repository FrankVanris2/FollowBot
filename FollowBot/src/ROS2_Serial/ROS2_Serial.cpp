/*
By: Frank Vanris
Date: 11/27/2024
Desc: Creating a testing env for ROS2 in order to determine if there is communication between both devices
*/

#include <ArduinoJson.h>
#include <Arduino.h>

#include "ROS2_Serial.h"
#include "sensors/Gyroscope.h"


//Singelton
ROS2_Serial ros2_serial;

ROS2_Serial::ROS2_Serial(): interval(TEST_INTERVAL), previousMillis(0) {}

void ROS2_Serial::ros2_loop() {
    if ((unsigned long) (millis() - previousMillis) >= interval) {
        previousMillis = millis();
        ros2SerialData();
        dataToSerial();

    } 
}

void ROS2_Serial::ros2SerialData() {
    if(Serial.available() > 0) {
        String message = Serial.readStringUntil('\n');
        Serial.print(message);
        Serial.println(" from Pi");
    } else {
        Serial.println("Data Not Received");
    }
}

void ROS2_Serial::dataToSerial() {
    const double* gyroData = gyroscope.getGyroData();
    
    // Create a JSON object
    StaticJsonDocument<256> doc; // Adjust the size based on your data complexity

    doc["sensor_type"] = "imu";
    JsonObject data = doc.createNestedObject("data");
    data["ax"] = gyroData[AX];
    data["ay"] = gyroData[AY];
    data["az"] = gyroData[AZ];
    data["gx"] = gyroData[GX];
    data["gy"] = gyroData[GY];
    data["gz"] = gyroData[GZ];

    //Serialize the JSON object to a string and send it over Serial
    serializeJson(doc, Serial);
    Serial.println();
}