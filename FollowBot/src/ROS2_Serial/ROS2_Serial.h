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
#define DEFAULT_UPDATE_INTERVAL 1000 // 1 second between updates

/**
 * ROS2_Serial Class
 * 
 * Manages bidirectional serial communication with a ROS2 system.
 * Formats sensor data as standardized JSON messages and handles incoming commands.
 */
class ROS2_Serial {
public:
    /**
     * Constructor - initializes timing settings
     */
    ROS2_Serial();

    /**
     * Main update loop - call regularly from main Arduino loop
     * Handles both sending sensor data and receiving commands
     */
    void ros2_loop();

    /**
     * Process any incoming serial messages from ROS2
     */
    void ros2SerialData();

    /**
     * Send all current sensor data to ROS2
     */
    void dataToSerial();

    /**
     * Format and send IMU data as JSON
     * Format: {"sensor_type":"imu","data":{"ax":X,"ay":Y,"az":Z,"gx":X,"gy":Y,"gz":Z}}
     */
    void imuDataDoc();

    /**
     * Format and send encoder data as JSON
     * Format: {"sensor_type":"encoder","data":{"left_wheel_ticks":X,"right_wheel_ticks":Y}}
     * Note: Maps encoder data to match ROS2 conventions (left/right)
     */
    void encoderDataDoc();

    /**
     * Format and send robot GPS data as JSON
     * Format: {"sensor_type":"gps","data":{"latitude":X,"longitude":Y}}
     */
    void gpsDataDoc();

    /**
     * Format and send phone/goal GPS data as JSON
     * Format: {"sensor_type":"goal","data":{"latitude":X,"longitude":Y}}
     */
    void phoneGPSDataDoc();
    
private:
    const unsigned long TEST_INTERVAL = DEFAULT_UPDATE_INTERVAL; // Communication interval;
    unsigned long interval;         // Current interval setting (configurable)
    unsigned long previousMillis;   // Timestamp of last update
};

// Global singleton instance
extern ROS2_Serial ros2_serial;