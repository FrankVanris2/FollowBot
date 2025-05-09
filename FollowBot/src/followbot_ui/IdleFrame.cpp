/*
By: Frank Vanris
Date: 5/9/2025
Desc: Creating an idle screen, a screen that will be printed out when things are being set up.
*/

#include <TFT_eSPI.h>

#include "IdleFrame.h"
#include "Button.h"
#include "TextBase.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"

// Singelton Object
IdleFrame idleFrame;

void IdleFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[IDLE_TEXT] = new TextBase(tft, 170, 140, "Idle", 5, TFT_BLACK, TFT_WHITE);
    getComponents()[IDLE_STAND_BY_TEXT] = new TextBase(tft, 30, 30, "Stand by", TEXT_SIZE, TFT_BLACK, TFT_WHITE);
    getComponents()[IDLE_TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[IDLE_TEXT_WAIT])->setHide(true);

    getComponents()[IDLE_TEXT_CONNECTION_STATUS] = new TextBase(tft, 155, 250);
    getComponents()[TEXT_IDLE_MESSAGE] = new TextBase(tft, 5, 300, "Idle", TEXT_SIZE, TFT_WHITE, TFT_RED);
}

void IdleFrame::loop() {
    if (!mTimerStarted) {
        mStartTime = millis();
        mTimerStarted = true;
    }

    if (mTimerStarted && (millis() - mStartTime >= IDLE_TIME_INTERVAL)) {
        mTimerStarted = false;
        myLCDScreen.setCurrentFrame(MAIN_SCREEN);
    }
}

void IdleFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}