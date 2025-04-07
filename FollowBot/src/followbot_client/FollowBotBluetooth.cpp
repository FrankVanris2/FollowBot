/*
By: Frank Vanris
Date: 3/16/2025
Desc: Creating a bluetooth connection
*/

#include "FollowBotBluetooth.h"
#include "following_mechanics/FollowMechanics.h"
#include "states&types/FollowBotNavigation.h"



//Singelton
FollowBotBluetooth followBotBluetooth;

BLEService followBotGPSService("12345678-1234-5678-1234-56789abcdef0");
BLECharacteristic followBotGPSCharacteristic("87654321-4321-8765-4321-0fedcba98765", BLERead | BLEWrite, 20);
BLECharacteristic followBotEnabledCharacteristic("11112222-3333-4444-5555-666677778888", BLERead | BLEWrite, 1);


FollowBotBluetooth::FollowBotBluetooth() : mIsError(false), mIsEnabled(false), previousMillis(0), interval(100) {
}

void FollowBotBluetooth::blePeripheralConnectHandler(BLEDevice central) {
Serial.println(String("Connected event, central: ") + central.address() + ", name: " + central.localName());
}

void FollowBotBluetooth::blePeripheralDisconnectHandler(BLEDevice central) {
Serial.println(String("Disconnected event, central: ") + central.address() + ", name: " + central.localName());
}

void FollowBotBluetooth::followBotGPSCharacteristicWritten(BLEDevice central, BLECharacteristic characteristic) {
    union {
        float floatArray[2];
        char charArray[8]; 
    } data;

    characteristic.readValue(data.charArray, sizeof(data.charArray)); // Read the value into the union
    
    followBotBluetooth.mobileGPSData.lat = data.floatArray[0];
    followBotBluetooth.mobileGPSData.lon = data.floatArray[1];
    followBotBluetooth.mIsEnabled = true;

    char buff[30];

    Serial.print("Characteristic event, latitude: ");
    snprintf (buff, sizeof(buff), "%.15f", data.floatArray[0]);
    Serial.print(buff);
    Serial.print(", longitude: ");
    snprintf (buff, sizeof(buff), "%.15f", data.floatArray[1]);
    Serial.println(buff);
}

void FollowBotBluetooth::followBotEnabledCharacteristicWritten(BLEDevice central, BLECharacteristic characteristic) {
    if (characteristic.written()) {
        byte value;
        characteristic.readValue(&value, 1);
        followBotBluetooth.mIsEnabled = value == 1;
        Serial.println(String("Enabled characteristic written: ") + value);
    }
}

void FollowBotBluetooth::setup() {
    // Initialize BLE
    if (!BLE.begin()) {
        Serial.println("Starting BLE failed!");
        mIsError = true;
        return;
    }
    Serial.println("BLE started");

    // Set the local name and service
    BLE.setLocalName("FollowBot_Proto1");
    BLE.setAdvertisedService(followBotGPSService);
    followBotGPSService.addCharacteristic(followBotGPSCharacteristic);
    BLE.addService(followBotGPSService);
    followBotEnabledCharacteristic.setEventHandler(BLEWritten, followBotEnabledCharacteristicWritten); // Adding a new event handler
  
    // Set the callbacks
    BLE.setEventHandler(BLEConnected, blePeripheralConnectHandler);
    BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);
    followBotGPSCharacteristic.setEventHandler(BLEWritten, followBotGPSCharacteristicWritten);
  
    // Start advertising
    BLE.advertise();
    Serial.println("BLE advertising started");
}

void FollowBotBluetooth::loop() {
    if ((millis() - previousMillis) >= interval) {
        previousMillis = millis();
        // Listen for BLE events
        BLE.poll();
        mRSSI = BLE.rssi();
        Serial.println(String("FollowBotBluetooth.loop - RSSI: ") + mRSSI);
    }
}
