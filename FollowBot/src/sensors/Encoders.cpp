/*
By: Frank Vanris
Date: 4/10/2025
Desc: Creating setup code for obtaining the rotations of the wheels through the encoders that will be installed
*/

#include "Encoders.h"
#include "config.h"

#include <Arduino.h>


// The Encoder gives 48 CPR (counts per revolution)

//Singleton
Encoders encoders;

// Static Variable definition
volatile double Encoders::mPositionRight = 0.0;
volatile double Encoders::mPositionLeft = 0.0;

Encoders::Encoders() : currentTime(0), previousTime(0),
previousPositionRight(0), previousPositionLeft(0) {}

void Encoders::setupEncoders() {
    pinMode(ENCODER_OUT_A, INPUT);
    pinMode(ENCODER_OUT_B, INPUT);
    pinMode(ENCODER_OUT_A2, INPUT);
    pinMode(ENCODER_OUT_B2, INPUT);

    attachInterrupt(digitalPinToInterrupt(ENCODER_OUT_A), readEncoderRight, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODER_OUT_A2), readEncoderLeft, RISING);
}

void Encoders::loopEncoders() {
    // time difference
    currentTime = micros();
    
   // Debug information
   // Serial.println(String("Encoder 1 num ticks: ") + mPosition1);
   // Serial.println(String("Encoder 2 num ticks: ") + mPosition2);

    if(currentTime - previousTime >= THREE_SECONDS * 1000) {
        previousTime = currentTime;
        setEncoderData(mPositionRight, mPositionLeft);

        previousPositionRight = mPositionRight;
        previousPositionLeft = mPositionLeft;
    }
}

float Encoders::getAverageDistance() const {
    return (getDistanceMetersRight() + getDistanceMetersLeft()) / 2.0f;
}

float Encoders::getDistanceMetersRight() const {
    return mPositionRight * METERS_PER_TICK;
}

float Encoders::getDistanceMetersLeft() const {
    return mPositionLeft * METERS_PER_TICK;
}

void Encoders::readEncoderRight() {
    int b = digitalRead(ENCODER_OUT_B);
    if (b == HIGH) {
        mPositionRight++;
    } else {
        mPositionRight--;
    }
}

void Encoders::readEncoderLeft() {
    int b = digitalRead(ENCODER_OUT_B2);
    if (b == HIGH) {
        mPositionLeft++; // originally --
    } else {
        mPositionLeft--; // originally ++
    }
}