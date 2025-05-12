/*
By: Frank Vanris
Date: 5/9/2025
Desc: Creating an idle screen, a screen that will be printed out when things are being set up
*/

#pragma once

#include <unordered_map>
#include "FrameBase.h"

class TFT_eSPI;

enum IdleFrameComponents {
    IDLE_TEXT,
    IDLE_STAND_BY_TEXT,
    IDLE_TEXT_WAIT,
    IDLE_TEXT_CONNECTION_STATUS,
    TEXT_IDLE_MESSAGE
};

class IdleFrame : public FrameBase<IdleFrameComponents> {
public:
    virtual void setup(TFT_eSPI& tft);
    virtual void draw();
    void loop() override; // Overriding the base class method.

private:
    unsigned long mStartTime = 0;
    bool mTimerStarted = false;
    const unsigned long IDLE_TIME_INTERVAL = 2000; // 2 seconds

};

extern IdleFrame idleFrame;