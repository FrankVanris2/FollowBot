/*
By: Frank Vanris
Date: 2/9/2025
Desc: Creating a secure way to store your credentials 
*/


#include "secrets/SecureWifiCredentials.h"
#include <EEPROM.h>

SecureWifiCredentials::SecureWifiCredentials() {
}

void SecureWifiCredentials::saveCredentials(const char* ssid, const char* password) {
    EEPROM.begin();
    //Store SSID
    for (int i = 0; i < 32; i++) {
        EEPROM.write(i, ssid[i]);
    }
    //Store Password
    for (int i = 32; i < 96; i++) {
        EEPROM.write(i, password[i - 32]);
    }
}

void SecureWifiCredentials::loadCredentials(char* ssid, char* password) {
    for (int i = 0; i < 32; i++) {
        ssid[i] = EEPROM.read(i);
    }
    for (int i = 32; i < 96; i++) {
        password[i - 32] = EEPROM.read(i);
    }
}