/*
 * BatteryReader.h
 * By: Frank Vanris
 * Date: 5/7/2025
 * 
 * Description:
 * Header file for the battery monitoring system that reads voltage levels
 * through a voltage divider and calculates remaining battery percentage.
 */

#pragma once
#include <Arduino.h>
#include <cmath>

// ADC and voltaage constants
const int ADC_MAX_VALUE = 1023; // Maximum value for a 10-bit ADC (0-1023)
const float FULLY_CHARGED_PERCENTAGE = 100.0f; 
const int FULL_BATTERY_PERCENTAGE = 100;
const int EMPTY_BATTERY_PERCENTAGE = 0; 

// Battery voltage thresholds
const float MAX_VOLTAGE = 12.0f;    // Voltage at 100% charge
const float MIN_VOLTAGE = 5.0f;     // Voltage at 0% charge

/**
 * BatteryReader Class
 * 
 * Monitors battery voltage through a voltage divider connected to an analog pin.
 * Provides both raw percentage and formatted string output of battery level.
 */
class BatteryReader {
public:
    /**
     * Constructor - initializes pin, resistor values, and timing parameters
     */
    BatteryReader();

    /**
     * Main loop function - reads voltage and updates battery percentage
     * Should be called regularly from the main program loop
     */
    void batteryReaderLoop();

    /**
     * Returns the current battery percentage as a float value (0-100)
     */
    float getBatteryPercentage() const { 
        return mBatteryPercentage; 
    } 

    /**
     * Returns battery percentage as a formatted string (e.g. "85%")
     * Rounds to nearest integer for display purposes
     */
    String getBatteryPercentageString() const {
        return String(std::round(mBatteryPercentage)) + "%"; 
    }

private:
    // Hardware configuration
    const int batteryPin;   // Analog input pin
    const float R1;         // Upper resistor in voltage divider (ohms)
    const float R2;         // Lower resistor in voltage divider (ohms)
    const float referenceVoltage; // ADC reference voltage

    // Time tracking
    unsigned long interval;     // Reading interval (ms)
    unsigned long previousMillis;   
    
    // State
    float mBatteryPercentage;   // Current battery level (0-100%)
};

// Global instance
extern BatteryReader batteryReader; // Singleton instance of BatteryReader