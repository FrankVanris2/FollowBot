/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating an SSID Frame that will allow the user to input their SSID information that will be safely stored in the EEPROM
*/

#pragma once

#include <unordered_map>
#include "FrameBase.h"

class TFT_eSPI;

enum SSIDFrameComponents {
    BACK_BUTTON,
    SSID_TEXT,
    SSID_INPUT_BOX, 
    NO_UI_COMPONENT,
    SSID_TEXT_WAIT,
};

class SSIDFrame : public FrameBase<SSIDFrameComponents> {
public:
    virtual void setup(TFT_eSPI& tft);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);

};

extern SSIDFrame ssidFrame;