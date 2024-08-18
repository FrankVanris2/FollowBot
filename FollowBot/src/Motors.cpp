/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: A motor class that will store all the types of motors that will be used
* for this project.
*/

#include "Motors.h"
#include "MotorControlStates.h"
#include <AFMotor.h>
#include "Arduino.h"

// Universal Object
Motors myMotors;


//Motors
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// My constructor
Motors::Motors(): input(0), lastInputTime(0) {

}

//where I initialize my motors
void Motors::motorSetup() {

    //setting speeds of all motors to high
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
}



void Motors::motorLoop() {  
    int numBytes = Serial.available();
    
    if(numBytes > 0) {
        input = Serial.read();
        lastInputTime = millis();
        switch(input) {
            case MOTOR_FORWARD:
                motorForwards();
                break;
            
            case MOTOR_BACKWARD:
                motorBackwards();
                break;
            
            case MOTOR_LEFT:
                motorLeft();
                break;
            
            case MOTOR_RIGHT: 
                motorRight();
                break;
            
            case MOTOR_RELEASE:
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
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

// Backward motions with the motors
void Motors::motorBackwards() {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

// Left motions with the motors
void Motors::motorLeft() {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

// Right motions with the motors
void Motors::motorRight() {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void Motors::motorStop() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}