/*
By: Frank Vanris
Date: 11/27/2024
Desc: Creating a testing env for ROS2 in order to determine if there is communication between both devices
*/

#include "ros2Testing.h"
#include "Arduino.h"

//Universal Object

ROS2_Testing ros2_TestingObj;

void ROS2_Testing::ros2_loop() {
    //testing ROS2 Serial reading and writing feature
    Serial.println("Hello World");
    delay(1000);

    if(Serial.available() > 0) {
        String message = Serial.readStringUntil('\n');
        Serial.print(message);
        Serial.println(" from arduino");
    } else {
        Serial.println("Data Not Received");
    }
    delay(1000);
}