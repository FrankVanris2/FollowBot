/*
By: Frank Vanris
Date: 3/16/2025
Desc: Creating a bluetooth connection
*/

#include <ArduinoBLE.h>

#include "FollowBotBluetooth.h"

//Singelton
FollowBotBluetooth followBotBluetooth;

BLEService followBotGPSService("12345678-1234-5678-1234-56789abcdef0");
BLECharacteristic followBotGPSCharacteristic("87654321-4321-8765-4321-0fedcba98765", BLERead | BLEWrite, 20);


void blePeripheralConnectHandler(BLEDevice central) {
Serial.println(String("Connected event, central: ") + central.address() + ", name: " + central.localName());
}

void blePeripheralDisconnectHandler(BLEDevice central) {
Serial.println(String("Disconnected event, central: ") + central.address() + ", name: " + central.localName());
}

void followBotGPSCharacteristicWritten(BLEDevice central, BLECharacteristic characteristic) {
    union {
        float floatArray[2];
        char charArray[8]; 
    } data;

    characteristic.readValue(data.charArray, sizeof(data.charArray)); // Read the value into the union

    char buff[30];

    Serial.print("Characteristic event, latitude: ");
    snprintf (buff, sizeof(buff), "%.15f", data.floatArray[0]);
    Serial.print(buff);
    Serial.print(", longitude: ");
    snprintf (buff, sizeof(buff), "%.15f", data.floatArray[1]);
    Serial.println(buff);
}
  

FollowBotBluetooth::FollowBotBluetooth() : isError(false) {
    // Constructor implementation
}

void FollowBotBluetooth::setup() {
    // Initialize BLE
    if (!BLE.begin()) {
        Serial.println("Starting BLE failed!");
        isError = true;
        return;
    }
    Serial.println("BLE started");

    // Set the local name and service
    BLE.setLocalName("FollowBot_Proto1");
    BLE.setAdvertisedService(followBotGPSService);
    followBotGPSService.addCharacteristic(followBotGPSCharacteristic);
    BLE.addService(followBotGPSService);
  
    // Set the callbacks
    BLE.setEventHandler(BLEConnected, blePeripheralConnectHandler);
    BLE.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);
    followBotGPSCharacteristic.setEventHandler(BLEWritten, followBotGPSCharacteristicWritten);
  
    // Start advertising
    BLE.advertise();
    Serial.println("BLE advertising started");
}

void FollowBotBluetooth::loop() {
    // Listen for BLE events
    BLE.poll();
}
