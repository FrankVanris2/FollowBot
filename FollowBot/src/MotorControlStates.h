/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: States that will be used when controlling the robot
*/

#pragma once

enum MotorControl {
    MOTOR_FORWARD = 'w',
    MOTOR_BACKWARD = 's',
    MOTOR_LEFT = 'a',
    MOTOR_RIGHT = 'd',
    MOTOR_RELEASE = 'q',
};