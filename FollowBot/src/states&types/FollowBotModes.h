/*
* By: Frank Vanris
* Date: 8/17/2024
* Desc: These are the modes that will change the screen of the TFT Display, along with how the robot functions.
*/

#pragma once
#include <Arduino.h>

// TODO: change this enums goddamnit Frank i.e. IDLE = 0
const String IDLE = "Idle";
const String MANUAL = "MANUAL"; // manual
const String FOLLOWING = "FOLLOWING"; // following
const String MAPPING = "MAPPING";
const String ERROR = "Error";