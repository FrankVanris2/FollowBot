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
#include "motion/motion.h"


ROS2_Serial ros2_serial;

// Json Documents
JsonDocument doc;

ROS2_Serial::ROS2_Serial() : 
    interval(TEST_INTERVAL), 
    previousMillis(0) 
{}

void ROS2_Serial::ros2_loop() {
    unsigned long currentMillis = millis();

    if ((currentMillis - previousMillis) >= interval) {
        previousMillis = currentMillis;
        readSerialData();
        writeSerialData();
    }
}

void ROS2_Serial::readSerialData() {
    Serial.println("BEFORE_SERIAL_ARD_ACK");
    if(Serial.available() > 0) {
        String message = Serial.readStringUntil('\n');
        Serial.print("Received: ");
        Serial.println(message);

        doc.clear();
        DeserializationError error = deserializeJson(doc, message);

        if (error) {
            Serial.println("JSON_ERROR_ACK"); // Acknowledge error command
            Serial.print("JSON Error: ");
            Serial.println(error.c_str());
            return;
        }

        // handle cmd_vel commands
        if (doc["sensor_type"] == "cmd_vel") {
            float linear = doc["data"]["linear"]["x"];
            float angular = doc["data"]["angular"]["z"];
            Serial.println("ARDUINO_CMD_VEL_ACK"); // Acknowledge command
            //Motion::getInstance().setVelocity(linear, angular);
        }
        // add other message types here as needed
    }
    Serial.println("OUTSIDE_SERIAL_ARD_ACK");
}

void ROS2_Serial::writeSerialData() {
    imuDataDoc();
    encoderDataDoc();
    gpsDataDoc();
}

void ROS2_Serial::imuDataDoc() {
    const double* gyroData = gyroscope.getGyroData();
    
    doc.clear();
    doc["sensor_type"] = "imu";
    JsonObject imuData = doc.createNestedObject("data");
    imuData["ax"] = gyroData[AX];
    imuData["ay"] = gyroData[AY];
    imuData["az"] = gyroData[AZ];
    imuData["gx"] = gyroData[GX];
    imuData["gy"] = gyroData[GY];
    imuData["gz"] = gyroData[GZ];

    serializeJson(doc, Serial);
    Serial.println();
}

void ROS2_Serial::encoderDataDoc() {
    const double* encoderData = encoders.getEncoderData();

    doc.clear();
    doc["sensor_type"] = "encoder";
    JsonObject encodeData = doc.createNestedObject("data");
    encodeData["left_wheel_ticks"] = encoderData[MOTOR_DISTANCE_IN_TICKS_LEFT]; // This is LEFT
    encodeData["right_wheel_ticks"] = encoderData[MOTOR_DISTANCE_IN_TICKS_RIGHT]; // This is RIGHT (Weird I know)
    
    serializeJson(doc, Serial);
    Serial.println();
}

void ROS2_Serial::gpsDataDoc() {
    if (myGPS.getRobotGPSData().lat == 0.0 && myGPS.getRobotGPSData().lon == 0.0) {
        
        return;         // If GPS data is equal to zero, return
    }

    doc.clear();
    doc["sensor_type"] = "gps";
    JsonObject gpsDataDoc = doc.createNestedObject("data");
    gpsDataDoc["latitude"] = myGPS.getRobotGPSData().lat;
    gpsDataDoc["longitude"] = myGPS.getRobotGPSData().lon;

    serializeJson(doc, Serial);
    Serial.println();
}

