/*
By: Frank Vanris
Date: 11/27/2024
Desc: Creating a testing env for ROS2 in order to determine if there is communication between both devices
*/

#include "ROS2_Serial.h"
#include "Arduino.h"

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
    Serial.println("Hello from Arduino");
}