/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating an SSID Frame that will allow the user to input their SSID information that will be safely stored in the EEPROM
*/

#pragma once

#include <unordered_map>
#include "FrameBase.h"

class TFT_eSPI;

enum WiFiCredentialsFrameComponents {
    WIFI_BACK_BUTTON,
    WIFI_SSID_TEXT,
    WIFI_SSID_INPUT_BOX, 
    WIFI_PASSWORD_TEXT,
    WIFI_PASSWORD_INPUT_BOX,
    WIFI_SAVE_BUTTON,
    WIFI_SAVE_TEXT,
    WIFI_TEXT_WAIT,
};

class WiFiCredentials : public FrameBase<WiFiCredentialsFrameComponents> {
public:
    virtual void setup(TFT_eSPI& tft);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);

private:
    void setSSID(const String& ssid);
    void setPassword(const String& password);
};

extern WiFiCredentials wifiCredentials;