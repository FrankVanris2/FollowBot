/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: A motor class that will store all the types of motors that will be used
* for this project.
*/
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

#include "Motors.h"
#include "objectavoidance&detection/ObjectAvoidance.h"
#include "states&types/MotorControlStates.h"
#include "followbot_manager/FollowBotManager.h"

const int MAX_SPEED = 255;
const int MED_SPEED = 200;
const int LOW_SPEED = 150;

const int ANGLE_THRESHOLD = 45; // degrees

// Universal Object
Motors myMotors;

// Create motor shield object with the default 12C address
Adafruit_MotorShield motorShield = Adafruit_MotorShield();

// Select which port
Adafruit_DCMotor *motor1 = motorShield.getMotor(1);
Adafruit_DCMotor *motor2 = motorShield.getMotor(2);
Adafruit_DCMotor *motor3 = motorShield.getMotor(3);
Adafruit_DCMotor *motor4 = motorShield.getMotor(4);

// My constructor
Motors::Motors(): mCurrentDirection(MOTOR_STOP) {}

//where I initialize my motors
void Motors::motorSetup() {
    Serial.println("Motor Setup");

    if (!motorShield.begin()) {         // create with the default frequency 1.6KHz
        // if (!motorShield.begin(1000)) {  // OR with a different frequency, say 1KHz
        Serial.println("Could not find Motor Shield. Check wiring.");
        while (1);
    }
    Serial.println("Motor Shield found.");
    
    //setting speeds of all motors to high
    motor1->setSpeed(MAX_SPEED);
    motor2->setSpeed(MAX_SPEED);
    motor3->setSpeed(MAX_SPEED);
    motor4->setSpeed(MAX_SPEED);
}

void Motors::motorLoop() {  
    
   if(mNewDirection != mCurrentDirection) {
        Serial.print("Motors.motorLoop - Updated Motor Direction: ");
        Serial.println(mNewDirection);
       mCurrentDirection = mNewDirection;
       adjustDirection();
   } 
}

void Motors::setMotorSpeed(int leftSpeed, int rightSpeed) {
    motor1->setSpeed(leftSpeed);
    motor2->setSpeed(rightSpeed);
    motor3->setSpeed(rightSpeed);
    motor4->setSpeed(leftSpeed);
    motorForwards();
}

//testing client, (very important)
void Motors::adjustDirection() {
    Serial.println(String("Motors.adjustDirection - Current Direction: ") + mCurrentDirection); 
    if (mCurrentDirection == MOTOR_FORWARD) {
        motorForwards();
    } else if (mCurrentDirection == MOTOR_BACKWARD) {
        motorBackwards();
    } else if (mCurrentDirection == MOTOR_LEFT) {
        motorLeft();
    } else if (mCurrentDirection == MOTOR_RIGHT) {
        motorRight();
    } else if (mCurrentDirection == MOTOR_STOP) {
        motorStop();
    }
}

void Motors::turn(float turn) {
    if (turn > ANGLE_THRESHOLD) {
        motorRight();
    } else if (turn < -ANGLE_THRESHOLD) {
        motorLeft();
    } else {
        motorForwards();
    }
}

void Motors::moveForward() {
    motorForwards();
}

void Motors::moveBackward() {
    motorBackwards();
}

void Motors::stopMoving() {
    motorStop();
}

// Forward motion with the motors
void Motors::motorForwards() {
    Serial.println("Motors.motorForwards()");
    motor1->run(FORWARD);
    motor2->run(FORWARD);
    motor3->run(BACKWARD);
    motor4->run(BACKWARD);
}

// Backward motions with the motors
void Motors::motorBackwards() {
    Serial.println("Motors.motorBackwards()");
    motor1->run(BACKWARD);
    motor2->run(BACKWARD);
    motor3->run(FORWARD);
    motor4->run(FORWARD);
}

// Left motions with the motors
void Motors::motorLeft() {
    Serial.println("Motors.motorLeft()");
    motor1->run(BACKWARD);
    motor2->run(FORWARD);
    motor3->run(BACKWARD);
    motor4->run(FORWARD);
}

// Right motions with the motors
void Motors::motorRight() {
    Serial.println("Motors.motorRight()");
    motor1->run(FORWARD);
    motor2->run(BACKWARD);
    motor3->run(FORWARD);
    motor4->run(BACKWARD);
}

void Motors::motorStop() {
    Serial.println("Motors.motorStop()");
    motor1->run(RELEASE);
    motor2->run(RELEASE);
    motor3->run(RELEASE);
    motor4->run(RELEASE);
}