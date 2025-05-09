/*
By: Frank Vanris
Date: 5/7/2025
Desc: Creating a Battery reader that reads the level of the battery
*/

#pragma once
#include <Arduino.h>
#include <cmath>

const int ADC_MAX_VALUE = 1023; // Maximum value for a 10-bit ADC
const float FULLY_CHARGED_PERCENTAGE = 100.0f; // Percentage when battery is fully charged
const int FULL_BATTERY_PERCENTAGE = 100;
const int EMPTY_BATTERY_PERCENTAGE = 0; // Percentage when battery is empty
const float MAX_VOLTAGE = 12.0f;
const float MIN_VOLTAGE = 5.0f; 

class BatteryReader {

public:

    BatteryReader();

    void batteryReaderLoop();

    float getBatteryPercentage() const { return mBatteryPercentage; } // Getter for battery percentage

    String getBatteryPercentageString() const {
        return String(std::round(mBatteryPercentage)) + "%"; // Return battery percentage as a string
    }

private:
    const int batteryPin;
    unsigned long interval;
    unsigned long previousMillis;   
    
    float mBatteryPercentage;
    const float R1;
    const float R2;
    const float referenceVoltage; // Reference Arduino ADC voltage

};

extern BatteryReader batteryReader; // Singleton instance of BatteryReader