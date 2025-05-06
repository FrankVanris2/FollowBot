/*
By: Frank Vanris
Date 2/11/2025
Desc: Creating the Main frame*/

#include <TFT_eSPI.h>

#include "MainFrame.h"
#include "Button.h"
#include "TextBase.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"
#include "followbot_client/FollowBotClient.h"

//Universal Object
MainFrame mainFrame;

void MainFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);

    getComponents()[BUTTON_INPUT_CREDENTIALS] = new Button(tft, 150, 75, 180, 50, "Wifi setup", 10);
    getComponents()[BUTTON_CONNECT] = new Button(tft, 150, 175, 180, 50, "Connect", 10);
    getComponents()[TEXT_CONNECTION_STATUS] = new TextBase(tft, 155, 250);

    getComponents()[TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[TEXT_WAIT])->setHide(true);
}

void MainFrame::wifiClientSetup() {
    ((TextBase*) getComponents()[TEXT_WAIT])->setHideAndDraw(false);
    ((TextBase*) getComponents()[TEXT_CONNECTION_STATUS])->setTextAndDraw("Connecting...");
    followBotClient.followBotClient_Setup();
    ((TextBase*) getComponents()[TEXT_CONNECTION_STATUS])->setTextAndDraw(followBotClient.isConnected() ? "Connected" : "Not Connected");
    ((TextBase*) getComponents()[TEXT_WAIT])->setHideAndDraw(true);
}

void MainFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool MainFrame::touchScreenEvent(int x, int y) {
    FrameComponents selected = getComponentForTouch(x, y);

    switch(selected) {
        case BUTTON_INPUT_CREDENTIALS: 
            Serial.println("Credentials button pressed"); 
            ((TextBase*) getComponents()[TEXT_WAIT])->setHide(false);
            getComponents()[TEXT_WAIT]->draw();
            myLCDScreen.setCurrentFrame(WIFI_CREDENTIALS_SCREEN); // Transition to WiFi Credentials Screen
            ((TextBase*) getComponents()[TEXT_WAIT])->setHide(true);
            return true;

        case BUTTON_CONNECT: 
            Serial.println("Connect button pressed"); 
            wifiClientSetup();
            return true;

        default:
            Serial.println("Unknown button pressed");
            return false;
    }
}

// New method to handle transitions to other screens
void MainFrame::handleScreenTransition(ScreenFrames targetScreen) {
    Serial.print("Transitioning to screen: ");
    Serial.println(targetScreen);

    switch (targetScreen) {
        case MAIN_SCREEN:
            Serial.println("Already on Main Screen.");
            break;

        case WIFI_CREDENTIALS_SCREEN:
            Serial.println("Switching to WiFi Credentials Screen.");
            myLCDScreen.setCurrentFrame(WIFI_CREDENTIALS_SCREEN);
            break;

        case KEYBOARD_SCREEN:
            Serial.println("Switching to Keyboard Screen.");
            myLCDScreen.setCurrentFrame(KEYBOARD_SCREEN);
            break;

        case idle_SCREEN:
            Serial.println("Switching to Idle Screen.");
            myLCDScreen.setCurrentFrame(idle_SCREEN);
            break;

        case Map_SCREEN:
            Serial.println("Switching to Map Screen.");
            myLCDScreen.setCurrentFrame(Map_SCREEN);
            break;

        case manual_CONTROL_SCREEN:
            Serial.println("Switching to Manual Control Screen.");
            myLCDScreen.setCurrentFrame(manual_CONTROL_SCREEN);
            break;

        default:
            Serial.println("Unknown screen transition requested.");
            break;
    }
}