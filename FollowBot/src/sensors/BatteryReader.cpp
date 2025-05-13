/*
 * BatteryReader.cpp
 * By: Frank Vanris
 * Date: 5/7/2025
 * 
 * Description:
 * Implementation of battery monitoring system that reads voltage from a 
 * battery through a voltage divider and calculates remaining charge percentage.
 * 
 * Circuit:
 * Battery+ --- R1 (5.1k) --- Analog Pin A0 --- R2 (2k) --- GND
 */

#include "BatteryReader.h"
#include <Arduino.h>

// Singleton instance
BatteryReader batteryReader; 

/**
 * Constructor - initializes pin configuration and voltage divider values.
 */
BatteryReader::BatteryReader(): 
    batteryPin(A0),             // Analog pin connected to battery voltage divider
    R1(5100.0f),                // 5.1k ohm resistor (connect to battery positive)
    R2(2000.0f),                // 2k ohm resistor (connect to ground)      
    referenceVoltage(3.3f),     // Arduino analog reference voltage (3.3V)
    interval(1000),             // Interval for reading battery voltage (1 second)
    previousMillis(0),          // Time tracking for interval
    mBatteryPercentage(0.0f)    // Intitialize percentage to 0
{}

/**
 * Main update loop for battery monitoring
 * - Reads battery voltage through voltage divider
 * - Calculates actual battery voltage accounting for the voltage divider
 * - Converts voltage to percentage based on min/max voltage range
 */
void BatteryReader::batteryReaderLoop() {
    unsigned long currentMillis = millis(); 

    // Only update at specified intervals to avoid excessive readings
    if ((currentMillis - previousMillis) >= interval) {
        previousMillis = currentMillis;
        
        // Read raw ADC value (0-1023 for 10-bit ADC)
        int rawValue = analogRead(batteryPin);
        
        // Convert raw ADC value to voltage at the pin
        float voltage = (float)rawValue / ADC_MAX_VALUE * referenceVoltage;

        // Calculate actual battery voltage using voltage divider formula
        // Vbattery = Vpin * (R1 + R2) / R2
        float batteryVoltage = voltage * ((R1 + R2) / R2);

        // Convert voltage to percentage based on battery's discharge curve
        // Linear approximation: 0% at MIN_VOLTAGE and 100% at MAX_VOLTAGE
        mBatteryPercentage = ((batteryVoltage - MIN_VOLTAGE) / 
                             (MAX_VOLTAGE - MIN_VOLTAGE)) * FULLY_CHARGED_PERCENTAGE;

        // Ensure percentage stays within valid range (0-100%)
        mBatteryPercentage = constrain(mBatteryPercentage, 
                                      EMPTY_BATTERY_PERCENTAGE, 
                                      FULL_BATTERY_PERCENTAGE);

        
        // Debugging purposes:
        // Log battery information every 10 seconds (10 intervals)
        // static int logCounter = 0;
        // if(++logCounter >= 10) {
        //     logCounter = 0;
        //     Serial.print("Battery: ");
        //     Serial.print(batteryVoltage, 2); // Display with 2 decimal places
        //     Serial.print(" V, (");
        //     Serial.print(mBatteryPercentage, 1); // Display with 1 decimal place
        //     Serial.println("%)");
        // }
    }
}