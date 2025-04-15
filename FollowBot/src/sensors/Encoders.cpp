/*
By: Frank Vanris
Date: 4/10/2025
Desc: Creating setup code for obtaining the rotations of the wheels through the encoders that will be installed
*/

#include "Encoders.h"
#include "config.h"

#include <Arduino.h>


// The Encoder gives 48 CPR (counts per revolution)

//Singelton
Encoders encoders;

// Static Variable definition
volatile long Encoders::mPosition1 = 0;
volatile long Encoders::mPosition2 = 0;

Encoders::Encoders() : currentTime(0), previousTime(0),
previousPosition1(0), previousPosition2(0) {}

void Encoders::setupEncoders() {
    pinMode(ENCODER_OUT_A, INPUT);
    pinMode(ENCODER_OUT_B, INPUT);
    pinMode(ENCODER_OUT_A2, INPUT);
    pinMode(ENCODER_OUT_B2, INPUT);

    attachInterrupt(digitalPinToInterrupt(ENCODER_OUT_A), readEncoder1, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODER_OUT_A2), readEncoder2, RISING);
}

void Encoders::loopEncoders() {

    // time difference
    currentTime = micros();
    
   // Debug information
   Serial.println(String("Encoder 1 num ticks: ") + mPosition1);
   Serial.println(String("Encoder 2 num ticks: ") + mPosition2);

    if(currentTime % THREE_SECONDS == 0) {
        setEncoderData(mPosition1, mPosition2);

        previousPosition1 = mPosition1;
        previousPosition2 = mPosition2;
        mPosition1 = 0;
        mPosition2 = 0;
    }

}

void Encoders::readEncoder1() {
    int b = digitalRead(ENCODER_OUT_B);
    if (b == HIGH) {
        mPosition1++;
    } else {
        mPosition1--;
    }
}

void Encoders::readEncoder2() {
    int b = digitalRead(ENCODER_OUT_B2);
    if (b == HIGH) {
        mPosition2--;
    } else {
        mPosition2++;
    }
}




