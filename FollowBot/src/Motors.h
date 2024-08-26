/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: This is the motors file where it will store all the motor methods.
*/

#pragma once
#include "Arduino.h"

class Motors {
public:

    Motors();

    void motorSetup();
    void motorLoop();

private:
    void adjustDirection();

    void motorForwards();
    void motorBackwards();
    void motorLeft();
    void motorRight();
    void motorStop();
    
    String mCurrentDirection;
};

extern Motors myMotors;