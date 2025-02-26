
/*
By: Frank Vanris
Date 2/9/2025
Desc: Creating a safer way in storing private information
*/

#pragma once
#include <Arduino.h>

class EEPROMStorage {        
    const int SSID_START_POS = 0;
    const int SSID_SIZE = 21;

    const int PASSWORD_START_POS = 21;
    const int PASSWORD_SIZE = 21;   

public:
    void setup();


    const String& getSSID() {
        return mSsid;
    }

    void setSSID(const String& ssid) {
        mSsid = ssid.substring(0, SSID_SIZE - 1);
    } 

    const String& getPassword() {
        return mPassword;
    }

    void setPassword(const String& password) {
        mPassword = password.substring(0, PASSWORD_SIZE - 1);
    } 

    void retrieveWiFiCredentials();
    void saveWiFiCredentials();

private:
   String mSsid;
   String mPassword; 

   void readStringFromEEPROM(int start, String& string);
   void writeStringToEEPROM(int start, const String& string);
};

extern EEPROMStorage eepromStorage;
