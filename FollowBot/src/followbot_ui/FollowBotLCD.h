/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to allow the user to input their ssid and pass for the robot in order for it to connect to the server
*/

#pragma once
#include "TFT_eSPI.h"
#include "TFT_eWidget.h"
#include "Button.h"



class LCDScreen {
public:

    LCDScreen();
    void myLCDScreen_Setup();
    void myLCDScreen_Loop();

private:
    TFT_eSPI tft;    
};

extern LCDScreen myLCDScreen;