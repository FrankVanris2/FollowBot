/*
 * ROS2_Serial.cpp
 * By: Frank Vanris
 * Date: 11/27/2024
 * 
 * Description:
 * Implementation of ROS2 serial communication interface.
 * Manages bidirectional communication between Arduino and ROS2 system:
 * 1. Formats and sends sensor data as JSON messages
 * 2. Receives and processes commands from ROS2
 * 
 * Message format:
 * {"sensor_type":"<type>","data":{<key-value pairs>}}
 */

#include <ArduinoJson.h>
#include <Arduino.h>

#include "ROS2_Serial.h"
#include "sensors/Gyroscope.h"
#include "sensors/Encoders.h"
#include "gps/GPS.h"
#include "followbot_client/FollowBotBluetooth.h"


// Singleton instance
ROS2_Serial ros2_serial;

/**
 * Constructor - initializes communication parameters
 */
ROS2_Serial::ROS2_Serial(): interval(TEST_INTERVAL), previousMillis(0) {}

/**
 * Main update loop - handles timing of serial communications
 */
void ROS2_Serial::ros2_loop() {
    unsigned long currentMillis = millis();

    if ((currentMillis - previousMillis) >= interval) {
        previousMillis = currentMillis;

        // Check for incoming commands first
        ros2SerialData();

        // Then send out sensor data
        dataToSerial();
    } 
}

/**
 * Process any incoming messages from ROS2
 */
void ROS2_Serial::ros2SerialData() {
    if(Serial.available() > 0) {
        // Read the incoming message
        String message = Serial.readStringUntil('\n');

        // TODO: Parse and process incoming commands
        // Possible implementation:
        // StaticJsonDocument<128> doc;
        // DeserializationError error = deserializeJson(doc, message);
        // if (error) {
        //    String command = doc["command"];
        //    // Process command...
        // }

        // Echo the received message (for debugging)
        //Serial.print("Received message: ");
        //Serial.print(message);
    } else {
        // Consider commenting this out in production to reduce serial traffic
        Serial.println("Pi is not sending any data");
    }
}

/**
 * Send all sensor data to ROS2
 */
void ROS2_Serial::dataToSerial() {
    // Send each sensor data type as a separate JSON message
    imuDataDoc();           // IMU (accelerometer and gyroscope)
    encoderDataDoc();       // Wheel encoders
    gpsDataDoc();           // Robot GPS position
}

/**
 * Format and send IMU data
 */
void ROS2_Serial::imuDataDoc() {
    // Get latest IMU readings
    const double* gyroData = gyroscope.getGyroData();

    // Create JSON document (capacity optimized for IMU data)
    StaticJsonDocument<128> imuDoc; 

    // Format as standardized message
    imuDoc["sensor_type"] = "imu";
    JsonObject imuData = imuDoc.createNestedObject("data");

    // Add all 6 IMU values
    imuData["ax"] = gyroData[AX];   // X-axis acceleration
    imuData["ay"] = gyroData[AY];   // Y-axis acceleration
    imuData["az"] = gyroData[AZ];   // Z-axis acceleration
    imuData["gx"] = gyroData[GX];   // X-axis angular velocity
    imuData["gy"] = gyroData[GY];   // Y-axis angular velocity
    imuData["gz"] = gyroData[GZ];   // Z-axis angular velocity

    // Send the JSON document
    serializeJson(imuDoc, Serial);
    Serial.println();   // End message with newline
}

/**
 * Format and send encoder data
 */
void ROS2_Serial::encoderDataDoc() {
    // Get latest encoder readings
    const double* encoderData = encoders.getEncoderData();

    // Create JSON document (optimized size for encoder data)
    StaticJsonDocument<96> encoderDoc;

    // Format as standardized message
    encoderDoc["sensor_type"] = "encoder";
    JsonObject encodeData = encoderDoc.createNestedObject("data");

    // Map the encoder data to match ROS2 conventions
    // Note: Hardware naming is inverted:
    // - MOTOR_DISTANCE_IN_TICKS_1 is RIGHT motor 
    // - MOTOR_DISTANCE_IN_TICKS_2 is LEFT motor
    encodeData["left_wheel_ticks"] = encoderData[MOTOR_DISTANCE_IN_TICKS_2]; 
    encodeData["right_wheel_ticks"] = encoderData[MOTOR_DISTANCE_IN_TICKS_1];
    
    // Send the JSON document
    serializeJson(encoderDoc, Serial);
    Serial.println();   // End message with newline
}

/**
 * Format and send robot GPS data
 */
void ROS2_Serial::gpsDataDoc() {
    // If GPS data is equal to zero, return
    if (myGPS.getRobotGPSData().lat == 0.0 && myGPS.getRobotGPSData().lon == 0.0) {
        return;
    }

    // Create JSON document (optimized size for GPS data)
    StaticJsonDocument<128> gpsDoc; 

    // Format as standardized message
    gpsDoc["sensor_type"] = "gps";
    JsonObject gpsDataDoc = gpsDoc.createNestedObject("data");

    // Add current robot GPS position
    gpsDataDoc["latitude"] = myGPS.getRobotGPSData().lat;
    gpsDataDoc["longitude"] = myGPS.getRobotGPSData().lon;

    // Send the JSON document
    serializeJson(gpsDoc, Serial);
    Serial.println();   // End message with newline
}

/**
 * Format and send phone/goal GPS data
 */
void ROS2_Serial::phoneGPSDataDoc() {
    // Create JSON document (optimized size for GPS data)
    StaticJsonDocument<128> phoneGPSDoc; 

    // Format as standardized message for goal position
    phoneGPSDoc["sensor_type"] = "goal";
    JsonObject phoneGPSDataDoc = phoneGPSDoc.createNestedObject("data");

    // Add current goal position from phone
    phoneGPSDataDoc["latitude"] = followBotBluetooth.getMobileGPSData().lat;
    phoneGPSDataDoc["longitude"] = followBotBluetooth.getMobileGPSData().lon;

    // Send the JSON document
    serializeJson(phoneGPSDoc, Serial);
    Serial.println();   // End message with newline
}