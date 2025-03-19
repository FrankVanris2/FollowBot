/*
By: Frank Vanris
Date: 2/26/2025
Desc: Creating a gyroscope which is needed for mapping
*/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "Gyroscope.h"
#include "followbot_manager/FollowBotManager.h"


Adafruit_MPU6050 mpu; 

//Singelton
Gyroscope gyroscope;

Gyroscope::Gyroscope(): interval(500), previousMillis(0) {}

void Gyroscope::gyroscope_Setup() {

    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        while(1) {
            delay(10);
        }
    }
    Serial.println("MPU6050 Found!");
}

void Gyroscope::gyroscope_Loop() {
    if ((millis() - previousMillis) >= interval) {
        previousMillis = millis();
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
    
        setGyroData(a.acceleration.x, a.acceleration.y, a.acceleration.z, g.gyro.x, g.gyro.y, g.gyro.z);
        followBotManager.setTemperatureParams(temp.temperature);
    } 
}