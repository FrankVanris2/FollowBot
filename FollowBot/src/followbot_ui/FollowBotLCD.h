/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to allow the user to input their ssid and pass for the robot in order for it to connect to the server
*/

#pragma once
#include "TFT_eSPI.h"
#include "TFT_eWidget.h"
#include "Button.h"
#include "ScreenState.h"


class UIComponent;

class LCDScreen {
public:
    void myLCDScreen_Setup();
    void myLCDScreen_Loop();
    void setCurrentFrame(ScreenFrames newFrame);

    int16_t getWidth() {
        return 480;
    }

    int16_t getHeight() {
        return 320;
    }

private:
    TFT_eSPI tft; 
    UIComponent* mCurrentFrame; 
};

extern LCDScreen myLCDScreen;