/*
By: Frank Vanris
Date: 5/9/2025
Desc: Creating a manual mode screen. Where if the user is in manual mode it will show this 
screen on the TFT screen.
*/

#pragma once

#include <unordered_map>
#include "FrameBase.h"

class TFT_eSPI;

enum ManualFrameComponents {
    MANUAL_TEXT,
    MANUAL_TEXT_WAIT,
    TO_MAIN_SCREEN_MANUAL,
};

class ManualFrame : public FrameBase<ManualFrameComponents> {
public:
    virtual void setup(TFT_eSPI& tft);
    virtual void draw();
    virtual bool touchScreenEvent(int x, int y);
    void loop() override; // Overriding the base class method.
};

extern ManualFrame manualFrame;