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

    void motorFowards();

    void motorBackwards();

    void motorLeft();
    
    void motorRight();

private:
    int input;
};

extern Motors myMotors;