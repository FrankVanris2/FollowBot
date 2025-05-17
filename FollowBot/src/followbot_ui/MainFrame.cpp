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
#include "followbot_manager/FollowBotManager.h"
#include "sensors/BatteryReader.h"

//Singelton Object
MainFrame mainFrame;

void MainFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
 
    getComponents()[BUTTON_INPUT_CREDENTIALS] = new Button(tft, 150, 75, 180, 50, "Wifi setup", 10);
    getComponents()[BUTTON_CONNECT] = new Button(tft, 150, 175, 180, 50, "Connect", 10);
    getComponents()[BUTTON_START_FOLLOWING] = new Button(tft, 330, 129, 120, 40, "follow", 10);
    getComponents()[TEXT_CONNECTION_STATUS] = new TextBase(tft, 155, 250);

    getComponents()[TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[TEXT_WAIT])->setHide(true);

    // Adding the battery display in top right corner
    getComponents()[TEXT_BATTERY_STATUS] = new TextBase(tft, 335, 15, "Batt: ---", 2, TFT_BLACK, TFT_WHITE);
}

void MainFrame::loop() {
    // updating battery status every 5 seconds.
    updateBatteryStatus();
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
            Serial.println("Credentials  button pressed"); 
            ((TextBase*) getComponents()[TEXT_WAIT])->setHide(false);
            getComponents()[TEXT_WAIT]->draw();
            myLCDScreen.setCurrentFrame(WIFI_CREDENTIALS_SCREEN);
            ((TextBase*) getComponents()[TEXT_WAIT])->setHide(true);
            return true;

        case BUTTON_CONNECT: 
            Serial.println("Connect button pressed"); 
            wifiClientSetup();
            return true;
        case BUTTON_START_FOLLOWING:
            Serial.println("Start Following button pressed");
            ((TextBase*) getComponents()[TEXT_WAIT])->setHide(false);
            getComponents()[TEXT_WAIT]->draw();
            followBotManager.setCurrentControl(FOLLOWING);
            myLCDScreen.setCurrentFrame(FOLLOWING_SCREEN);
            ((TextBase*) getComponents()[TEXT_WAIT])->setHide(true);
            return true;
    }
    return false;
}

void MainFrame::updateBatteryStatus() {
    unsigned long currentMillis = millis();

    // Only check battery every 5 seconds
    if (currentMillis - mLastBatteryCheckTime >= BATTERY_CHECK_INTERVAL) {
        mLastBatteryCheckTime = currentMillis;
        
        // Get the battery percentage string using your existing Battery Reader
        String newBatteryStatus = "Batt: " + batteryReader.getBatteryPercentageString();

        // Only update display if value changed
        if (newBatteryStatus != mLastBatteryStatus) {
            mLastBatteryStatus = newBatteryStatus;
            ((TextBase*) getComponents()[TEXT_BATTERY_STATUS])->setTextAndDraw(newBatteryStatus);
        }
    }
}