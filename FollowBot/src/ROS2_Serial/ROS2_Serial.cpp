/*
By: Frank Vanris
Date: 11/27/2024
Desc: Creating a testing env for ROS2 in order to determine if there is communication between both devices
*/

#include <ArduinoJson.h>
#include <Arduino.h>

#include "ROS2_Serial.h"
#include "sensors/Gyroscope.h"
#include "sensors/Encoders.h"
#include "gps/GPS.h"
#include "motion/motion.h"

//#include "followbot_client/FollowBotBluetooth.h"

ROS2_Serial ros2_serial;

ROS2_Serial::ROS2_Serial(): interval(TEST_INTERVAL), previousMillis(0) {}

// TODO: change name to serial_loop
void ROS2_Serial::ros2_loop() {
    if ((millis() - previousMillis) >= interval) {
        previousMillis = millis();
        readSerialData();
        writeSerialData();
    } 
}

void ROS2_Serial::readSerialData() {
    if(Serial.available() > 0) {
        String message = Serial.readStringUntil('\n');
        Serial.print("Received: ");
        Serial.println(message);

        StaticJsonDocument<256> doc;
        DeserializationError error = deserializeJson(doc, message);

        if (error) {
            Serial.print("JSON Error: ");
            Serial.println(error.c_str());
            return;
        }

        // handle cmd_vel commands
        if (doc["sensor_type"] == "cmd_vel") {
            float linear = doc["data"]["linear"]["x"];
            float angular = doc["data"]["angular"]["z"];
            motion.setVelocity(linear, angular);
        }
        // add other message types here as needed
    }
}

void ROS2_Serial::writeSerialData() {
    imuDataDoc();
    encoderDataDoc();
    gpsDataDoc();
    phoneGPSDataDoc();
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

    serializeJson(imuDoc, Serial);
    Serial.println();
}

void ROS2_Serial::encoderDataDoc() {
    const double* encoderData = encoders.getEncoderData();
    StaticJsonDocument<256> encoderDoc;

    encoderDoc["sensor_type"] = "encoder";
    JsonObject encodeData = encoderDoc.createNestedObject("data");
    encodeData["left_wheel_ticks"] = encoderData[MOTOR_DISTANCE_IN_TICKS_2]; // This is LEFT
    encodeData["right_wheel_ticks"] = encoderData[MOTOR_DISTANCE_IN_TICKS_1]; // This is RIGHT (Weird I know)
    
    serializeJson(encoderDoc, Serial);
    Serial.println();
}

void ROS2_Serial::gpsDataDoc() {
    StaticJsonDocument<256> gpsDoc; 

    gpsDoc["sensor_type"] = "gps";
    JsonObject gpsDataDoc = gpsDoc.createNestedObject("data");
    gpsDataDoc["latitude"] = myGPS.getRobotGPSData().lat;
    gpsDataDoc["longitude"] = myGPS.getRobotGPSData().lon;

    serializeJson(gpsDoc, Serial);
    Serial.println();
}

void ROS2_Serial::phoneGPSDataDoc() {
    StaticJsonDocument<256> phoneGPSDoc; 

    // this is gps data from the phone
    phoneGPSDoc["sensor_type"] = "goal";
    JsonObject phoneGPSDataDoc = phoneGPSDoc.createNestedObject("data");
    phoneGPSDataDoc["latitude"] = followBotBluetooth.getMobileGPSData().lat;
    phoneGPSDataDoc["longitude"] = followBotBluetooth.getMobileGPSData().lon;

    serializeJson(phoneGPSDoc, Serial);
    Serial.println();
}