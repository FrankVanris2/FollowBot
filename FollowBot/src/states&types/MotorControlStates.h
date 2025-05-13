/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: States that will be used when controlling the robot
*/

#pragma once
#include <Arduino.h>

// Control modes as numeric constants
enum ControlMode {
    MODE_IDLE = 0,
    MODE_USER = 1,      // manual control
    MODE_ROBOT = 2,     // following mode
    MODE_MAPPING = 3,   // mapping mode
    MODE_ERROR = 4
};

// String representations for control modes (for display/debugging)
const String CONTROL_MODE_STRINGS[] = {
    "Idle",
    "User",     // manual
    "Robot",    // following
    "Mapping",
    "Error"
};

// Motor direction constants
enum MotorDirection {
    MOTOR_DIRECTION_STOP = 0,
    MOTOR_DIRECTION_FORWARD = 1,
    MOTOR_DIRECTION_BACKWARD = 2,
    MOTOR_DIRECTION_LEFT = 3,
    MOTOR_DIRECTION_RIGHT = 4
};

// String representations for motor directions (for display/debugging)
const String MOTOR_DIRECTION_STRINGS[] = {
    "Stop",
    "Forward",
    "Backward",
    "Left",
    "Right"
};

// Original MotorStates enum (kept for backward compatibility)
enum MotorStates {
    FORWARDS,
    BACKWARDS,
    LEFT,
    RIGHT,
    STOP,
};