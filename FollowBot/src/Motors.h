/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: This is the motors file where it will store all the motor methods.
*/

#pragma once
#include "Arduino.h"
#include "MotorControlStates.h"

class Motors {
public:

    Motors();

    void motorSetup();
    void motorLoop();

    void setDirection(String dir) {
        /*if (dir == MOTOR_FORWARD || dir == MOTOR_BACKWARD || dir == MOTOR_LEFT || dir == MOTOR_RIGHT || dir == MOTOR_STOP) {
            mNewDirection = dir;
        }  */
       mNewDirection = dir;   
    }

    void moveForwards(float distance) {
        mNewDirection = MOTOR_FORWARD;
    }

    void moveBackwards(float distance) {
        mNewDirection = MOTOR_BACKWARD;
    }

    void turnLeft(float rads) {
        mNewDirection = MOTOR_LEFT;
    }

    void turnRight(float rads) {
        mNewDirection = MOTOR_RIGHT;
    }

    void justStop() {
        mNewDirection = MOTOR_STOP;
    }
private:
    void motorForwards();
    void motorBackwards();
    void motorLeft();
    void motorRight();
    void motorStop();

    void adjustDirection();

    String mCurrentDirection;
    String mNewDirection;
};

extern Motors myMotors;