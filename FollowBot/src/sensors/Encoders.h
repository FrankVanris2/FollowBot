/*
By: Frank Vanris
Date: 4/10/2025
Desc: Creating encoders that will read rotation speed of the motors. the wheel Diameter will change consistently.
*/

#pragma once
#define ENCODER_OUT_A 3
#define ENCODER_OUT_B 4

class Encoders {
    
public:
    Encoders();

    void setupEncoders();

    void loopEncoders();

private:  
    long mPosition;
};