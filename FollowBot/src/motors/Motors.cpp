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
const int MIN_EFFECTIVE = 50;

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

void Motors::motorSetup() {
    Serial.println("Motor Setup");

    if (!motorShield.begin()) {             // create with the default frequency 1.6KHz
        // if (!motorShield.begin(1000)) {  // OR with a different frequency, say 1KHz
        Serial.println("Could not find Motor Shield. Check wiring.");
        while (1);
    }
    Serial.println("Motor Shield found.");
    
    //setting speeds of all motors to high
    motor1->setSpeed(MED_SPEED);
    motor2->setSpeed(MED_SPEED);
    motor3->setSpeed(MED_SPEED);
    motor4->setSpeed(MED_SPEED);
}

// TODO: change to new
void Motors::motorLoop() {
//   if(mNewDirection != mCurrentDirection) {
//        Serial.print("Motors.motorLoop - Updated Motor Direction: ");
//        Serial.println(mNewDirection);
//       mCurrentDirection = mNewDirection;
//       adjustDirection();
//   }

    Serial.println("test1 left wheel");
    setLeftRightSpeeds(100, 0);
    delay(2000);
    motorStop();

    Serial.println("test1 right wheel");
    setLeftRightSpeeds(0, 100);
    delay(2000);
    motorStop();

    Serial.println("test2");
    myMotors.setNormalizedSpeeds(0.3, 0.3);
    delay(2000);

    Serial.println("test3");
    myMotors.setNormalizedSpeeds(1.0, 1.0);
    delay(2000);

    Serial.print("stop");
    setNormalizedSpeeds(0, 0);
    delay(2000);
}

int Motors::scaleSpeed(float normalized) {
    // map [-1.0, 1.0] to [MIN_SPEED, MAX_SPEED]
    return constrain(
        (abs(normalized) * (MAX_SPEED - MIN_EFFECTIVE)) + MIN_EFFECTIVE,
        MIN_EFFECTIVE,
        MAX_SPEED
    ) * (normalized > 0 ? 1 : -1);
}

void Motors::setNormalizedSpeeds(float left, float right) {
    setLeftRightSpeeds(
        scaleSpeed(left),
        scaleSpeed(right)
    );
}

void Motors::setLeftRightSpeeds(int leftSpeed, int rightSpeed) {
    // left side motors (1 & 4)
    setMotorDirection(motor1, leftSpeed);
    setMotorDirection(motor4, leftSpeed);

    // right side motors (2 & 3)
    setMotorDirection(motor2, rightSpeed);
    setMotorDirection(motor3, rightSpeed);

    // set speeds after setting direction
    motor1->setSpeed(constrain(abs(leftSpeed), MIN_EFFECTIVE, MAX_SPEED));
    motor4->setSpeed(constrain(abs(leftSpeed), MIN_EFFECTIVE, MAX_SPEED));
    motor2->setSpeed(constrain(abs(rightSpeed), MIN_EFFECTIVE, MAX_SPEED));
    motor3->setSpeed(constrain(abs(rightSpeed), MIN_EFFECTIVE, MAX_SPEED));
}

void Motors::setMotorDirection(Adafruit_DCMotor* motor, int speed) {
    if(speed > 0) {
        motor->run(FORWARD);
    } else if(speed < 0) {
        motor->run(BACKWARD);
    } else {
        motor->run(RELEASE);
    }
}

/** BEGINNING OF LEGACY FUNCTIONS: */
void Motors::setMotorSpeed(int leftSpeed, int rightSpeed) {
    motor1->setSpeed(leftSpeed);
    motor2->setSpeed(rightSpeed);
    motor3->setSpeed(rightSpeed);
    motor4->setSpeed(leftSpeed);
    motorForwards();
}

// testing client, (very important)
void Motors::adjustDirection() {
    if (mUseVelocity) return; // skip if using new control

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
/** END OF LEGACY FUNCTIONS: */