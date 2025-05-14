/*
By: Frank Vanris
Date: 11/27/2024
Desc: Testing the ROS2 communication between the Raspberry Pi and the Arduino Board
*/

#pragma once

class ROS2_Serial {
public:

    ROS2_Serial();

    //loop method for testing purposes
    void ros2_loop();

    void readSerialData();
    void writeSerialData();

    void imuDataDoc();
    void encoderDataDoc();
    void gpsDataDoc();

private:
    const unsigned long TEST_INTERVAL = 1000;
    unsigned long interval;
    unsigned long previousMillis;

};

extern ROS2_Serial ros2_serial;