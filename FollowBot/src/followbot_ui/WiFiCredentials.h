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
    BACK_BUTTON,
    SSID_TEXT,
    SSID_INPUT_BOX, 
    PASSWORD_TEXT,
    PASSWORD_INPUT_BOX,
    NO_UI_COMPONENT,
    CRED_TEXT_WAIT,
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