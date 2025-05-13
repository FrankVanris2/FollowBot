/*
By: Frank Vanris
Date: 5/9/2025
Desc: Creating a manual mode screen. Where if the user is in manul mode it will show this
screen on the TFT screen.
*/

#include <TFT_eSPI.h>

#include "ManualFrame.h"
#include "Button.h"
#include "TextBase.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"
#include "followbot_manager/FollowBotManager.h"

// Singelton Object
ManualFrame manualFrame;

void ManualFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[MANUAL_TEXT] = new TextBase(tft, 90, 75, "Manual Mode", 5, TFT_BLACK, TFT_WHITE);
    getComponents()[TO_MAIN_SCREEN_MANUAL] = new Button(tft, 150, 195, 180, 50, "Main screen", 10);
    getComponents()[MANUAL_TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[MANUAL_TEXT_WAIT])->setHide(true);
}

void ManualFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool ManualFrame::touchScreenEvent(int x, int y) {
    ManualFrameComponents selected = getComponentForTouch(x, y);

    if(selected == TO_MAIN_SCREEN_MANUAL) {
        ((TextBase*) getComponents()[MANUAL_TEXT_WAIT])->setHide(false);
        getComponents()[MANUAL_TEXT_WAIT]->draw();
        myLCDScreen.setCurrentFrame(MAIN_SCREEN);
        ((TextBase*) getComponents()[MANUAL_TEXT_WAIT])->setHide(true);
        return true;
    }
    return false;
}

void ManualFrame::loop() {
    if (followBotManager.getCurrentControl() == ROBOT) {
        ((TextBase*) getComponents()[MANUAL_TEXT_WAIT])->setHide(false);
        getComponents()[MANUAL_TEXT_WAIT]->draw();
        myLCDScreen.setCurrentFrame(FOLLOWING_SCREEN);
        ((TextBase*) getComponents()[MANUAL_TEXT_WAIT])->setHide(true);
    } else if(followBotManager.getCurrentControl() == MAPPING) {
        // To Do 
    }
}