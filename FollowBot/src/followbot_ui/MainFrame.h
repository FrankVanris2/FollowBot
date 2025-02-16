/*
By: Frank Vanris
Date: 2/11/2025
Desc: The main frame where everything is projected with options
*/

#pragma once

#include "UIComponent.h"
#include "unordered_map"

class TFT_eSPI;

class MainFrame : public UIComponent {
public:

    void setup(TFT_eSPI&  tft);

    virtual void draw();
    virtual bool touchScreenEvent(int x, int y);

    

private:

    enum FrameComponents {
        BUTTON_SSID,
        BUTTON_PASSWORD,
        BUTTON_CONNECT,
        NO_UI_COMPONENT
    };

    std::unordered_map<FrameComponents, UIComponent*> comps;
};

extern MainFrame mainFrame;