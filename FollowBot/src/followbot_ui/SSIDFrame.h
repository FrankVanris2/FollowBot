/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating an SSID Frame that will allow the user to input their SSID information that will be safely stored in the EEPROM
*/

#pragma once
#include "UIComponent.h"
#include <unordered_map>

class TFT_eSPI;

class SSIDFrame : public UIComponent {
public:
    void setup(TFT_eSPI& tft);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);


private:
    enum FrameComponents {
        BACK_BUTTON,
        SSID_TEXT,
        SSID_INPUT_BOX, 
        NO_UI_COMPONENT
    };

    std::unordered_map<FrameComponents, UIComponent*> comps;

};

extern SSIDFrame ssidFrame;