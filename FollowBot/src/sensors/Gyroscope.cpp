/*
By: Frank Vanris
Date: 2/26/2025
Desc: Creating a gyroscope which is needed for mapping
*/

#include "Gyroscope.h"
#include "Adafruit_MPU6050.h"
#include "Adafruit_Sensor.h"
#include "Wire.h"

Adafruit_MPU6050 mpu; 

//Singelton
Gyroscope gyroscope;

Gyroscope::Gyroscope(): interval(200), previousMillis(0) {}

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
    if ((unsigned long) (millis() - previousMillis) >= interval) {
        previousMillis = millis();
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
    
        gyroData[0] = a.acceleration.x;
        gyroData[1] = a.acceleration.y;
        gyroData[2] = a.acceleration.z;
        gyroData[3] = g.gyro.x;
        gyroData[4] = g.gyro.y;
        gyroData[5] = g.gyro.z;

        Serial.print("Gyroscope Data: ");
        Serial.print(gyroData[0]);
        Serial.print(", ");
        Serial.print(gyroData[1]);
        Serial.print(", ");
        Serial.print(gyroData[2]);
        Serial.print(", ");
        Serial.print(gyroData[3]);
        Serial.print(", ");
        Serial.print(gyroData[4]);
        Serial.print(", ");
        Serial.println(gyroData[5]);
    } 
}