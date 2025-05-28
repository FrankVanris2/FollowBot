/*
 * ROS2_Serial.h
 * By: Frank Vanris
 * Date: 11/27/2024
 *
 * Description:
 * Handles serial communication between Arduino and ROS2 running on Raspberry Pi.
 * Formats sensor data (IMU, encoders, GPS) as JSON messages and sends through
 * the serial connection at regular intervals for processing by ROS2 nodes.
 */

#pragma once

// Communication timing constants
#define DEFAULT_UPDATE_INTERVAL 100  // 100 milliseconds between updates

/**
 * ROS2_Serial Class
 *
 * Manages bidirectional serial communication with a ROS2 system.
 * Formats sensor data as standardized JSON messages and handles incoming commands.
 */
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
    const unsigned long TEST_INTERVAL = DEFAULT_UPDATE_INTERVAL; // Communication interval;
    unsigned long interval;         // Current interval setting (configurable)
    unsigned long previousMillis;   // Timestamp of last update
};

extern ROS2_Serial ros2_serial;