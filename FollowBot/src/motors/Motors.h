/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: This is the motors file where it will store all the motor methods.
*/

#pragma once
#include <Arduino.h>

#include "states&types/MotorControlStates.h"
#include <Adafruit_MotorShield.h>

const int MOTOR_LEFT_OFFSET = 0; // Adjust as needed
const int MOTOR_RIGHT_OFFSET = 0; // Adjust as needed

class Motors {
public:

    Motors();


    void motorSetup();
    void motorLoop();

    void setControlMode(bool useVelocityControl) {
        mUseVelocity = useVelocityControl;
    }

    int scaleSpeed(float);
    void setNormalizedSpeeds(float left, float right);
    void setLeftRightSpeeds(int left, int right);
    void setMotorDirection(Adafruit_DCMotor* motor, int speed);


    void setMotorSpeed(int leftSpeed, int rightSpeed);

    void setDirection(String dir) {
       mNewDirection = dir;
    }

    const String& getDirection() const { return mNewDirection; }
    
    void moveForwards(float distance) { mNewDirection = MOTOR_FORWARD; }

    void moveBackwards(float distance) { mNewDirection = MOTOR_BACKWARD; }

    void turnLeft(float rads) { mNewDirection = MOTOR_LEFT; }

    void turnRight(float rads) { mNewDirection = MOTOR_RIGHT; }

    void justStop() { mNewDirection = MOTOR_STOP; }

    void moveForward();
    void moveBackward();
    void turn (float turn);
    void stopMoving();

private:
    bool mUseVelocity = false; // for safe rollback, default to legacy mode

    String mCurrentDirection;
    String mNewDirection;

    void adjustDirection();

    void motorForwards();
    void motorBackwards();
    void motorLeft();
    void motorRight();
    void motorStop();
};

extern Motors myMotors;