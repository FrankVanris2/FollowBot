/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: States that will be used when controlling the robot
*/

#pragma once
#include <Arduino.h>

// TODO: change this enums goddamnit Frank i.e. IDLE = 0
const String IDLE = "Idle";
const String MANUAL = "MANUAL"; // manual
const String FOLLOWING = "FOLLOWING"; // following
const String MAPPING = "MAPPING";
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