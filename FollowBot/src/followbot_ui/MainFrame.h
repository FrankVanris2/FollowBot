/*
By: Frank Vanris
Date: 2/11/2025
Desc: The main frame where everything is projected with options
*/

#pragma once

#include <unordered_map>
#include "FrameBase.h"

class TFT_eSPI;

enum FrameComponents {
    BUTTON_INPUT_CREDENTIALS,
    BUTTON_CONNECT,
    BUTTON_START_FOLLOWING,
    TEXT_WAIT,
    TEXT_CONNECTION_STATUS,
    TEXT_BATTERY_STATUS
};

class MainFrame : public FrameBase<FrameComponents>{
public:

    virtual void setup(TFT_eSPI&  tft);
    virtual void draw();
    virtual bool touchScreenEvent(int x, int y);
    void wifiClientSetup();
    void updateBatteryStatus();
    void loop() override; // Overriding the base class method.

private: 
    // We will be migrating the battery reading to a seperate class for printing battery. But for right now
    // we will keep it here for now.
    String mLastBatteryStatus = "";
    unsigned long mLastBatteryCheckTime = 0;
    const unsigned long BATTERY_CHECK_INTERVAL = 5000; // 5 seconds
};

extern MainFrame mainFrame;