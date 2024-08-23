/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: This is the motors file where it will store all the motor methods.
*/

#pragma once

class Motors {
public:

    Motors();

    void motorSetup();

    void motorLoop();

    
    // Testing purposes
    void motorClientTesting(char* movement);

private:

    //Important movements
    void motorForwards();

    void motorBackwards();

    void motorLeft();
    
    void motorRight();

    void motorStop();
    
    int input;
    unsigned long lastInputTime;
};

extern Motors myMotors;