/*
By: Frank Vanris
Date: 5/9/2025
Desc: Creating a Following Frame for when the robot is following a user
*/

#include <TFT_eSPI.h>

#include "FollowingFrame.h"
#include "Button.h"
#include "TextBase.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"
#include "followbot_manager/FollowBotManager.h"

// Singelton Object
FollowingFrame followingFrame;

void FollowingFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[FOLLOWING_TEXT] = new TextBase(tft, 110, 75, "Following", 5, TFT_BLACK, TFT_WHITE);
    getComponents()[TO_MAIN_SCREEN] = new Button(tft, 150, 195, 180, 50, "Main screen", 10);
    getComponents()[FOLLOWING_TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[FOLLOWING_TEXT_WAIT])->setHide(true);
}

void FollowingFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool FollowingFrame::touchScreenEvent(int x, int y) {
    FollowingFrameComponents selected = getComponentForTouch(x, y);

    if(selected == TO_MAIN_SCREEN) {
        ((TextBase*) getComponents()[FOLLOWING_TEXT_WAIT])->setHide(false);
        getComponents()[FOLLOWING_TEXT_WAIT]->draw();
        myLCDScreen.setCurrentFrame(MAIN_SCREEN);
        ((TextBase*) getComponents()[FOLLOWING_TEXT_WAIT])->setHide(true);
        return true;   
    }
    return false;
}

void FollowingFrame::loop() {
    if(followBotManager.getCurrentControl() == USER) {
        ((TextBase*) getComponents()[FOLLOWING_TEXT_WAIT])->setHide(false);
        getComponents()[FOLLOWING_TEXT_WAIT]->draw();
        myLCDScreen.setCurrentFrame(MANUAL_SCREEN);
        ((TextBase*) getComponents()[FOLLOWING_TEXT_WAIT])->setHide(true);
    } else if(followBotManager.getCurrentControl() == MAPPING) {
        // TODO: confirm this with Frank
        // Show mapping UI
        ((TextBase*) getComponents()[FOLLOWING_TEXT_MAPPING])->setHide(false);
        getComponents()[FOLLOWING_TEXT_MAPPING]->draw();

        // Example: Display coordinates
        String coordText = "LAT: " + String(followBotManager.getLat()) + " LNG: " + String(followBotManager.getLng());
        ((TextBase*) getComponents()[FOLLOWING_TEXT_COORD])->setText(coordText.c_str());
        ((TextBase*) getComponents()[FOLLOWING_TEXT_COORD])->draw();

        myLCDScreen.setCurrentFrame(MAPPING_SCREEN); // Switch to mapping screen

        // Hide elements after update
        ((TextBase*) getComponents()[FOLLOWING_TEXT_MAPPING])->setHide(true);
        ((TextBase*) getComponents()[FOLLOWING_TEXT_COORD])->setHide(true);
    }
}