
/*
By: Frank Vanris
Date 2/9/2025
Desc: Creating a safer way in storing private information
*/

#pragma once

class SecureWifiCredentials {
public:

    SecureWifiCredentials();

    void saveCredentials(const char* ssid, const char* password);

    void loadCredentials(char* ssid , char* password);

    char* getSSID() {
        return ssid;
    }

    char* getPassword() {
        return password;
    }




private:
   char ssid[32];
   char password[64]; 
};