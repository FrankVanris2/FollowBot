/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: A motor class that will store all the types of motors that will be used
* for this project.
*/
#include "Arduino.h"
#include "Motors.h"
#include "objectavoidance&detection/ObjectAvoidance.h"
#include "Wire.h"
#include "states&types/MotorControlStates.h"
#include "Adafruit_MotorShield.h"
#include "followbot_manager/FollowBotManager.h"
#include "Arduino_FreeRTOS.h"


const int MAX_SPEED = 255;
const int MED_SPEED = 200;
const int LOW_SPEED = 150;

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
Motors::Motors(): mCurrentDirection(MOTOR_STOP) {

}

//where I initialize my motors
void Motors::motorSetup() {
    Serial.println("Motor Setup");
    motorShield.begin();
    //setting speeds of all motors to high
    motor1->setSpeed(MED_SPEED);
    motor2->setSpeed(MED_SPEED);
    motor3->setSpeed(MED_SPEED);
    motor4->setSpeed(MED_SPEED);

}



void Motors::motorLoop() {  
    //testing purposes
    //Serial.print("New Direction: ");
    //Serial.println(mNewDirection);

    //Serial.print("Current Direction: ");
    //Serial.println(mCurrentDirection);
    
    if(mNewDirection != mCurrentDirection) {
        //Serial.print("Updated Motor Direction: ");
        //Serial.println(mNewDirection);
        mCurrentDirection = mNewDirection;
        adjustDirection();
    } 
}

//testing client, (very important)
void Motors::adjustDirection() {

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

// Forward motion with the motors
void Motors::motorForwards() {
    motor1->run(BACKWARD);
    motor2->run(BACKWARD);
    motor3->run(FORWARD);
    motor4->run(FORWARD);
}

// Backward motions with the motors
void Motors::motorBackwards() {
    motor1->run(FORWARD);
    motor2->run(FORWARD);
    motor3->run(BACKWARD);
    motor4->run(BACKWARD);
}

// Left motions with the motors
void Motors::motorLeft() {
    motor1->run(FORWARD);
    motor2->run(BACKWARD);
    motor3->run(FORWARD);
    motor4->run(BACKWARD);
}

// Right motions with the motors
void Motors::motorRight() {
    motor1->run(BACKWARD);
    motor2->run(FORWARD);
    motor3->run(BACKWARD);
    motor4->run(FORWARD);
}

void Motors::motorStop() {
    motor1->run(RELEASE);
    motor2->run(RELEASE);
    motor3->run(RELEASE);
    motor4->run(RELEASE);
}