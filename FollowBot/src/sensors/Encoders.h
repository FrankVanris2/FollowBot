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
    MOTOR_DISTANCE_IN_TICKS_1 = 0,
    MOTOR_DISTANCE_IN_TICKS_2,
};

class Encoders {   
public:
    Encoders();

    void setupEncoders();
    void loopEncoders();

    static void readEncoder1();
    static void readEncoder2();

    void setEncoderData(int numTicks1, int numTicks2) {
        encoderData[MOTOR_DISTANCE_IN_TICKS_1] = numTicks1;
        encoderData[MOTOR_DISTANCE_IN_TICKS_2] = numTicks2;
    }

    double* getEncoderData() { return encoderData; }


private:  
    static volatile double mPosition1;
    static volatile double mPosition2;

    int previousPosition1;
    int previousPosition2;

    unsigned long currentTime; 
    unsigned long previousTime;

    double encoderData[DATA_SIZE];
};

extern Encoders encoders;