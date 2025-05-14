/*
 * Encoders.h
 * By: Frank Vanris
 * Date: 4/10/2025
 * Desc: Interface for wheel rotation encoders using quadrature output.
 * 
 * Hardware Notes:
 * - The wheel encoders provide 48 CPR (counts per revolution)
 * - IMPORTANT: Encoder 1 is connected to the RIGHT motor
 * - IMPORTANT: Encoder 2 is connected to the LEFT motor
 */

#pragma once

// Constants
#define DATA_SIZE 2         // Number of encoders (left and right)
#define UPDATE_INTERVAL 3000  // Update interval in milliseconds

// Encoder pin definitions
#define ENCODER_OUT_A 2     // RIGHT motor encoder channel A (interrupt pin)
#define ENCODER_OUT_B 4     // RIGHT motor encoder channel B
#define ENCODER_OUT_A2 3    // LEFT motor encoder channel A (interrupt pin)
#define ENCODER_OUT_B2 5    // LEFT motor encoder channel B

// Indices for encoder data array
enum  MotorDistances {
    MOTOR_DISTANCE_IN_TICKS_1 = 0, // RIGHT motor ticks (Encoder 1)
    MOTOR_DISTANCE_IN_TICKS_2,     // Left motor ticks (Encoder 2)
};

/**
 * Manages wheel encoders to track rotation of both drive wheels
 */
class Encoders {   
public:
    /**
     * Constructor - initializes counters and timing variables
     */
    Encoders();

    /**
     * Configure encoder pins and attach interrupt handlers
     */
    void setupEncoders();

    /**
     * Process encoder data and update tick counts
     * Call regularly from the main loop
     */
    void loopEncoders();

    /**
     * Interrupt service routine for RIGHT motor encoder (Encoder 1)
     * Called when encoder pin triggers an interrupt
     */
    static void readEncoder1();

    /**
     * Interrupt service routine for LEFT motor encoder (Encoder 2)
     * Called when encoder pin triggers an interrupt
     */
    static void readEncoder2();

    /**
     * Store the current encoder tick counts in the data array
     * 
     * @param numTicks1 RIGHT motor tick count
     * @param numTicks2 LEFT motor tick count
     */
    void setEncoderData(int numTicks1, int numTicks2) {
        encoderData[MOTOR_DISTANCE_IN_TICKS_1] = numTicks1;
        encoderData[MOTOR_DISTANCE_IN_TICKS_2] = numTicks2;
    }

    /**
     * Get pointer to the encoder data array
     * [0] = RIGHT motor ticks, [1] = LEFT motor ticks
     * 
     * @return Array of encoder tick counts
     */
    double* getEncoderData() { return encoderData; }


private:  
    // Volatile variables are modified inside interrupts
    static volatile double mPosition1;  // RIGHT motor tick counter
    static volatile double mPosition2;  // LEFT motor tick counter

    int previousPosition1;              // Previous RIGHT motor position
    int previousPosition2;              // Previous LEFT motor position

    unsigned long currentTime;          // Current time in microseconds
    unsigned long previousTime;         // Last update time in microsecnds

    double encoderData[DATA_SIZE];      // Stores accumulated ticks for each encoder
};

// Global singleton instance
extern Encoders encoders;