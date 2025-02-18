/*
By: Frank Vanris
Date 2/11/2025
Desc: Creating the Main frame*/


#include "MainFrame.h"
#include "TFT_eSPI.h"
#include "Button.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"

//Universal Object
MainFrame mainFrame;

void MainFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);

    getComponents()[BUTTON_SSID] = new Button(tft, 140, 80, 200, 50, "SSID", 10);
    getComponents()[BUTTON_PASSWORD] = new Button(tft, 140, 160, 200, 50, "Password", 10);
    getComponents()[BUTTON_CONNECT] = new Button(tft, 180, 240, 120, 40, "Connect", 10);
}

void MainFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool MainFrame::touchScreenEvent(int x, int y) {
    FrameComponents selected = getComponentForTouch(x, y);

    switch(selected) {
        case BUTTON_SSID: 
            Serial.println("SSID button pressed"); 
            myLCDScreen.setCurrentFrame(SSID_SCREEN);
            return true;

        case BUTTON_PASSWORD: 
            Serial.println("Password button pressed"); 
            return true;

        case BUTTON_CONNECT: 
            Serial.println("Connect button pressed"); 
            return true;
    }
    return false;
}