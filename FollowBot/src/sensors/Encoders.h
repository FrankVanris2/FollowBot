/*
By: Frank Vanris
Date: 4/10/2025
Desc: Creating encoders that will read rotation speed of the motors. the wheel Diameter will change consistently.
*/

#pragma once

#define DATA_SIZE 2
#define THREE_SECONDS 3000

#define ENCODER_OUT_A 2
#define ENCODER_OUT_B 4

#define ENCODER_OUT_A2 3
#define ENCODER_OUT_B2 5

enum  MotorDistances {
    MOTOR_DISTANCE_IN_TICKS_RIGHT = 0,
    MOTOR_DISTANCE_IN_TICKS_LEFT,
};

class Encoders {   
public:
    Encoders();

    void setupEncoders();
    void loopEncoders();

    static void readEncoderRight();
    static void readEncoderLeft();
    float getAverageDistance() const;
    float getDistanceMetersRight() const;
    float getDistanceMetersLeft() const;

    void setEncoderData(int rightTicks, int leftTicks) {
        encoderData[MOTOR_DISTANCE_IN_TICKS_RIGHT] = rightTicks;
        encoderData[MOTOR_DISTANCE_IN_TICKS_LEFT] = leftTicks;
    }

    double* getEncoderData() { return encoderData; }


private:  
    static volatile double mPositionRight;
    static volatile double mPositionLeft;

    const float METERS_PER_TICK = (0.1963f / 48.0f);  // 0.1963m circumference / 48 ticks

    int previousPositionRight;
    int previousPositionLeft;

    unsigned long currentTime; 
    unsigned long previousTime;

    double encoderData[DATA_SIZE];
};

extern Encoders encoders;