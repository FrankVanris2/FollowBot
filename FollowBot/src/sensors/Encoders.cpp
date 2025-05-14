/*
 * Encoders.cpp
 * By: Frank Vanris
 * Date: 4/10/2025
 * Desc: Implementation for wheel rotation encoders.
 * 
 * Hardware Notes:
 * - The wheel encoders provide 48 CPR (counts per revolution)
 * - IMPORTANT: Encoder 1 (mPosition1) is connected to the RIGHT motor
 * - IMPORTANT: Encoder 2 (mPosition2) is connected to the LEFT motor
 * - Encoders use quadrature output (A & B channels) to detect direction
 */

#include "Encoders.h"
#include "config.h"
#include <Arduino.h>

// Singelton instance
Encoders encoders;

// Initialize static variables
volatile double Encoders::mPositionRight = 0.0; // RIGHT motor position
volatile double Encoders::mPositionLeft = 0.0; // Left motor position

/**
 * Constructor - initializes counter and timing variables
 */
Encoders::Encoders() : 
    currentTime(0), 
    previousTime(0),
    previousPositionRight(0), 
    previousPositionLeft(0) 
{
    // Initialize encoder data array
    for (int i = 0; i < DATA_SIZE; i++) {
        encoderData[i] = 0.0;
    }
}

/**
 * Configure encoder pins and attach interrupt handlers
 */
void Encoders::setupEncoders() {
    // Set pin modes for encoder inputs
    pinMode(ENCODER_OUT_A, INPUT);      // RIGHT encoder channel A
    pinMode(ENCODER_OUT_B, INPUT);      // RIGHT encoder channel B
    pinMode(ENCODER_OUT_A2, INPUT);     // LEFT encoder channel A
    pinMode(ENCODER_OUT_B2, INPUT);     // LEFT encoder channel B

    // Attach interrupt handlers for both encoders
    // RISING edge triggers an interrupt when the signal goes from low to high
    attachInterrupt(digitalPinToInterrupt(ENCODER_OUT_A), readEncoderRight, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODER_OUT_A2), readEncoderLeft, RISING);

    // Initialize timing
    previousTime = micros();
}  

/**
 * Process encoder data at regular intervals
 */
void Encoders::loopEncoders() {

    // Get current time in microseconds
    currentTime = micros();
    
   // Only update data at regular intervals (every UPDATE_INTERVAL milleseconds)
    if(currentTime - previousTime >= THREE_SECONDS) {
        // Save current tick counts to data array
        setEncoderData(mPositionRight, mPositionLeft);

        // Debug output (uncomment when needed)
        // Serial.println("Encoder data updated:");
        // Serial.println("  RIGHT motor (Encoder 1): " + String(mPosition1) + " ticks");
        // Serial.println("  LEFT motor (Encoder 2): " + String(mPosition2) + " ticks");
   
        // Save current position for next cycle
        previousPositionRight = mPositionRight;
        previousPositionLeft = mPositionLeft;

        // Reset counters for next interval
        mPositionRight = 0;
        mPositionLeft = 0;

        // Update time for next interval
        previousTime = currentTime;
    }
}

/**
 * Interrupt service routine for RIGHT motor encoder (Encoder 1)
 * Called on RISING edge of channel A
 */
void Encoders::readEncoderRight() {
    // Read channel B to determine direction
    int b = digitalRead(ENCODER_OUT_B);

    // Update position based on direction
    if (b == HIGH) {
        mPositionRight++;   // Forward rotation
    } else {
        mPositionRight--;   // Reverse rotation
    }
}

/**
 * Interrupt service routine for LEFT motor encoder (Encoder 2)
 * Called on RISING edge of channel A
 * 
 * Note: Direction is inverted compared to RIGHT encoder due to 
 * physical mounting orientation of the LEFT motor and encoder
 */
void Encoders::readEncoderLeft() {
    // Read channel B to determine direction
    int b = digitalRead(ENCODER_OUT_B2);

    // Direction is inverted for left motor due to physical mounting
    if (b == HIGH) {
        mPositionLeft--;   // Forward rotation (inverted)
    } else {
        mPositionLeft++;   // Reverse rotation (inverted)
    }
}




