/*
By: Frank Vanris
Date: 5/7/2025
Desc: Creating a Battery reader that reads the level of the battery
*/
#include "BatteryReader.h"
#include <Arduino.h>

BatteryReader batteryReader; // singelton instance of BatteryReader

BatteryReader::BatteryReader(): batteryPin(A0), R1(5100.0f), R2(2000.0f), referenceVoltage(5.0f) {}

void BatteryReader::batteryReaderLoop() {
    int rawValue = analogRead(batteryPin); // Read the raw ADC value
    float voltage = (rawValue / ADC_MAX_VALUE) * referenceVoltage;
    float batteryVoltage = voltage * ((R1 + R2) / R2);

    // Calculate battery percentage
    mBatteryPercentage = ((batteryVoltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE)) * FULLY_CHARGED_PERCENTAGE;

    // Ensure percentage stays within 0-100%
    mBatteryPercentage = constrain(mBatteryPercentage, EMPTY_BATTERY_PERCENTAGE, FULL_BATTERY_PERCENTAGE);
}