/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: A motor class that will store all the types of motors that will be used
* for this project.
*/

#include "Motors.h"
#include "Wire.h"
#include "MotorControlStates.h"
#include "Adafruit_MotorShield.h"
#include "Arduino.h"

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
Motors::Motors(): input(0), lastInputTime(0) {

}

//where I initialize my motors
void Motors::motorSetup() {
    motorShield.begin();
    //setting speeds of all motors to high
    motor1->setSpeed(255);
    motor2->setSpeed(255);
    motor3->setSpeed(255);
    motor4->setSpeed(255);
}



void Motors::motorLoop() {  
    int numBytes = Serial.available();
    
    if(numBytes > 0) {
        input = Serial.read();
        lastInputTime = millis();
        switch(input) {
            case MOTOR_FORWARD:
                Serial.println("Motor is Forward");
                motorForwards();
                break;
            
            case MOTOR_BACKWARD:
                Serial.println("Motor is Backward");
                motorBackwards();
                break;
            
            case MOTOR_LEFT:
            Serial.println("Motor is Left");
                motorLeft();
                break;
            
            case MOTOR_RIGHT: 
                Serial.println("Motor is Right");
                motorRight();
                break;
            
            case MOTOR_RELEASE:
            Serial.println("Motor is stop");
                motorStop();
                break;
        }   
    }
    
    if(millis() - lastInputTime >= 500) {
        motorStop(); // autostop
    }
}

// Forward motion with the motors
void Motors::motorForwards() {
    motor1->run(BACKWARD);
    motor2->run(FORWARD);
    motor3->run(FORWARD);
    motor4->run(BACKWARD);
}

// Backward motions with the motors
void Motors::motorBackwards() {
    motor1->run(FORWARD);
    motor2->run(BACKWARD);
    motor3->run(BACKWARD);
    motor4->run(FORWARD);
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