/*
By: Frank Vanris
Date: 4/10/2025
Desc: Creating setup code for obtaining the rotations of the wheels through the encoders that will be installed
*/

#include "Encoders.h"
#include "config.h"

#include <Arduino.h>


// The Encoder gives 48 CPR (counts per revolution)

//Singelton
Encoders encoders;

// Static Variable definition
volatile long Encoders::mPosition1 = 0;
volatile long Encoders::mPosition2 = 0;


Encoders::Encoders() : 
kp(1), kd(0), ki(0),
target(0), prevT(0),
eprev1(0), eprev2(2),
eintegral1(0.0), eintegral2(0.0) {}


void Encoders::setupEncoders() {
    pinMode(ENCODER_OUT_A, INPUT);
    pinMode(ENCODER_OUT_B, INPUT);
    pinMode(ENCODER_OUT_A2, INPUT);
    pinMode(ENCODER_OUT_B2, INPUT);

    attachInterrupt(digitalPinToInterrupt(ENCODER_OUT_A), readEncoder1, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODER_OUT_A2), readEncoder2, RISING);
}

void Encoders::loopEncoders() {
    Serial.println(String("Encoder 1 Position: ") + mPosition1);
    Serial.println(String("Encoder 2 Position: ") + mPosition2);

    // time difference
    long currT = micros();
    float deltaT = (currT - prevT) / 1.0e6;
    prevT = currT;

    // PID calculations for both motors
    float u1 = calculatePID(mPosition1, eprev1, eintegral1, deltaT);
    float u2 = calculatePID(mPosition2, eprev2, eintegral2, deltaT);

    // Motor power and direction (example for motor 1, same for motor 2)
    float pwr1 = fabs(u1) > 255 ? 255 : fabs(u1); 
    int dir1 = u1 < 0 ? -1 : 1; // Direction based on sign of u1

    float pwr2 = fabs(u2) > 255 ? 255 : fabs(u2);
    int dir2 = u2 < 0 ? -1 : 1; // Direction based on sign of u2

    
    // Send signals to motors (implement motor-specific code here)
    // Example: setMotorPower(dir1, pwr1);
    // Example: setMotorPower(dir2, pwr2);

   // Debug information
   Serial.println(String("Motor 1 Control Signal: ") + u1);
   Serial.println(String("Motor 2 Control Signal: ") + u2);

}

// Function to calculate PID output for each motor
float Encoders::calculatePID(long position, int &prevError, float &integral, float deltaT) {
    int error = position - target; // Calculate error
    float derivative = (error - prevError) / deltaT; // Calculate derivative
    integral += error * deltaT; // Calculate integral;
    prevError = error;
    return kp * error + kd * derivative + ki * integral; // Calculate PID output
}

float Encoders::convertTicksToMM(int numTicks) {
    // COnvert ticks to mm based on wheel circumference and encoder CPR
    float numRotations = float (numTicks / ENCODER_CPR);
    float distance = numRotations * WHEEL_CIRCUMFERENCE;
    return distance; // in mm
}

void Encoders::readEncoder1() {
    int b = digitalRead(ENCODER_OUT_B);
    if (b == HIGH) {
        mPosition1++;
    } else {
        mPosition1--;
    }
}

void Encoders::readEncoder2() {
    int b = digitalRead(ENCODER_OUT_B2);
    if (b == HIGH) {
        mPosition2++;
    } else {
        mPosition2--;
    }
}




