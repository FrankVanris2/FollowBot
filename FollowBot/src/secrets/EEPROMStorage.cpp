/*
By: Frank Vanris
Date: 2/9/2025
Desc: Creating a secure way to store your credentials 
*/

#include <EEPROM.h>
#include "secrets/EEPROMStorage.h"


// Singelton object 
EEPROMStorage eepromStorage;

void EEPROMStorage::setup() {
    retrieveWiFiCredentials();
}

void EEPROMStorage::retrieveWiFiCredentials() {
    readStringFromEEPROM(SSID_START_POS, mSsid);
    readStringFromEEPROM(PASSWORD_START_POS, mPassword);
    Serial.println(String("Retrieve: SSID: ") + mSsid + ", Password: " + mPassword);
    
}

void EEPROMStorage::readStringFromEEPROM(int start, String& string) {
    string = "";
    char chr = EEPROM.read(start);
    while (chr != '\0') {
        string += chr;
        chr = EEPROM.read(++start);
    }
}

void EEPROMStorage::saveWiFiCredentials() { 
    Serial.println(String("Save: SSID: ") + mSsid + ", Password: " + mPassword);
    writeStringToEEPROM(SSID_START_POS, mSsid);
    writeStringToEEPROM(PASSWORD_START_POS, mPassword);
}

void EEPROMStorage::writeStringToEEPROM(int start, const String& string) {
    Serial.println(String("Save String: ") + string);
    for (int idx = 0; idx < string.length(); idx++) {
        EEPROM.write(start + idx, string[idx]);
    }
    EEPROM.write(start + string.length(), '\0');
}
