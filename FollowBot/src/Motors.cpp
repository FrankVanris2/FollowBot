/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: A motor class that will store all the types of motors that will be used
* for this project.
*/

#include "Motors.h"
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
Motors::Motors(): input(0) {

}

//where I initialize my motors
void Motors::motorSetup() {  
    motor1.setSpeed(255);
    motor2.setSpeed(255);
    motor3.setSpeed(255);
    motor4.setSpeed(255);
}


void Motors::motorLoop() {
    if(Serial.available()) {
        input = Serial.read();
        if(input == '1') {
            motor1.run(FORWARD);
            delay(2000);
            motor1.run(RELEASE);
            delay(1000);
            motor1.run(BACKWARD);
            delay(2000);
            motor1.run(RELEASE);
            delay(1000);
        }
        if(input == '2') {
            motor2.run(FORWARD);
            delay(2000);
            motor2.run(RELEASE);
            delay(1000);
            motor2.run(BACKWARD);
            delay(2000);
            motor2.run(RELEASE);
            delay(1000);
        }
        if(input == '3') {
            motor3.run(FORWARD);
            delay(2000);
            motor3.run(RELEASE);
            delay(1000);
            motor3.run(BACKWARD);
            delay(2000);
            motor3.run(RELEASE);
            delay(1000);
        }
        if(input == '4') {
            motor4.run(FORWARD);
            delay(2000);
            motor4.run(RELEASE);
            delay(1000);
            motor4.run(BACKWARD);
            delay(2000);
            motor4.run(RELEASE);
            delay(1000);
        }
    }   
}