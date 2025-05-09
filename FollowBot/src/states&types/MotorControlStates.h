/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: States that will be used when controlling the robot
*/

#pragma once
#include <Arduino.h>

const String IDLE = "Idle";
const String USER = "User";
const String ROBOT = "Robot";
const String MAPPING = "Mapping";
const String ERROR = "Error";

const String MOTOR_FORWARD = "Forward";
const String MOTOR_BACKWARD = "Backward";
const String MOTOR_LEFT = "Left";
const String MOTOR_RIGHT = "Right";
const String MOTOR_STOP = "Stop";


enum MotorStates {
    FORWARDS,
    BACKWARDS,
    LEFT,
    RIGHT,
    STOP,
};