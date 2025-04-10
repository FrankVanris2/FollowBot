/*
By: Frank Vanris
Date: 4/10/2025
Desc: Creating setup code for obtaining the rotations of the wheels through the encoders that will be installed
*/

#include "Encoders.h"

#include <Encoder.h>
#include <Arduino.h>


Encoder myEncoder(ENCODER_OUT_A, ENCODER_OUT_B);

Encoders::Encoders() {}

void Encoders::setupEncoders() {
    Serial.println("Testing if encoders are working...");
}

void Encoders::loopEncoders() {
    long newPosition = myEncoder.read();
    if (newPosition != oldPosition) {
        oldPosition = newPosition;
        Serial.println(String("Original position: 0, New Position: ")  + newPosition);
    }
}




