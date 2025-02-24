
/*
By: Frank Vanris
Date 2/9/2025
Desc: Creating a safer way in storing private information
*/

#pragma once
#include <Arduino.h>

class SecureWifiCredentials {
public:

    SecureWifiCredentials();

    void saveCredentials(const char* ssid, const char* password);

    void loadCredentials(char* ssid , char* password);
    
    const String& getSSID() {
        return mSsid;
    }

    void setSSID(const String& ssid) {
        mSsid = ssid;
    } 

    const String& getPassword() {
        return mPassword;
    }

    void setPassword(const String& password) {
        mPassword = password;
    } 

private:
   String mSsid;
   String mPassword; 
};

extern SecureWifiCredentials secureWifiCredentials;
