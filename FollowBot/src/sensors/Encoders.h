/*
By: Frank Vanris
Date: 4/10/2025
Desc: Creating encoders that will read rotation speed of the motors. the wheel Diameter will change consistently.
*/

#pragma once

#define ENCODER_OUT_A 2
#define ENCODER_OUT_B 3

#define ENCODER_OUT_A2 4
#define ENCODER_OUT_B2 5

#define WHEEL_DIAMETER 62.48 // in mm
#define WHEEL_CIRCUMFERENCE (WHEEL_DIAMETER * 3.14) // in mm
#define ENCODER_CPR 48 // counts per revolution

class Encoders {
    
public:
    Encoders();

    void setupEncoders();
    void loopEncoders();

    static void readEncoder1();
    static void readEncoder2();
private:  

    float calculatePID(long position, int &prevError, float &integral, float deltaT);

    float convertTicksToMM(int numTicks);
    
    static volatile long mPosition1;
    static volatile long mPosition2;

    const float kp, kd, ki; // PID Constants
    int target;
    long prevT; // previous time

    int eprev1, eprev2;
    float eintegral1, eintegral2; // PID variables for both motors
};

extern Encoders encoders;