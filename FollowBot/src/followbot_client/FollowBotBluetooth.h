/*
By: Frank Vanris
Date: 3/16/2025
Desc: Creating a bluetooth connection for my arduino uno rev4 board.
*/

#pragma once
#include <ArduinoBLE.h>
#include "states&types/FollowBotNavigation.h"

class FollowBotBluetooth {

public:
    FollowBotBluetooth();
    void setup();
    void loop();

    bool isEnabled() const {
        return mIsEnabled; 
    }

    const GeoLoc& getMobileGPSData() const {
        return mobileGPSData; 
    }

    int getRSSI() const {
        return mRSSI; 
    }

private:
    unsigned long interval;
    unsigned long previousMillis; 

    bool mIsError;
    bool mIsEnabled;
    GeoLoc mobileGPSData;
    int mRSSI;



    static void blePeripheralConnectHandler(BLEDevice central);
    static void blePeripheralDisconnectHandler(BLEDevice central);
    static void followBotGPSCharacteristicWritten(BLEDevice central, BLECharacteristic characteristic);   
    static void followBotEnabledCharacteristicWritten(BLEDevice central, BLECharacteristic characteristic); 
};

extern FollowBotBluetooth followBotBluetooth; // Declare the singleton instance