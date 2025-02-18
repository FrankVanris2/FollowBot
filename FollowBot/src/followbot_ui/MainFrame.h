/*
By: Frank Vanris
Date: 2/11/2025
Desc: The main frame where everything is projected with options
*/

#pragma once

#include "unordered_map"
#include "FrameBase.h"

class TFT_eSPI;

enum FrameComponents {
    BUTTON_SSID,
    BUTTON_PASSWORD,
    BUTTON_CONNECT
};

class MainFrame : public FrameBase<FrameComponents>{
public:

    virtual void setup(TFT_eSPI&  tft);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);

 
};

extern MainFrame mainFrame;