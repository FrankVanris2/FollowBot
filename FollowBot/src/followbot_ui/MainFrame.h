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
    BUTTON_INPUT_CREDENTIALS,
    BUTTON_CONNECT,

    TEXT_WAIT,
    TEXT_CONNECTION_STATUS,

};

class MainFrame : public FrameBase<FrameComponents>{
public:

    virtual void setup(TFT_eSPI&  tft);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);

    void wifiClientSetup();
};

extern MainFrame mainFrame;