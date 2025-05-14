/*
By: Joseph
Date: 5/12/2025
Desc: Creating a mapping frame that would show up if the Mode is now mapping
*/

#include <TFT_eSPI.h>

#include "MappingFrame.h"
#include "Button.h"
#include "TextBase.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"
#include "followbot_manager/FollowBotManager.h"
#include "followbot_client/FollowBotBluetooth.h"

// Singelton Object
MappingFrame mappingFrame;
void MappingFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[MAPPING_TEXT] = new TextBase(tft, 110, 75, "Mapping", 5, TFT_BLACK, TFT_WHITE);
    getComponents()[TO_MAIN_SCREEN_MAPPING] = new Button(tft, 150, 195, 180, 50, "Main screen", 10);
    getComponents()[FOLLOWING_TEXT_COORD] = new TextBase(tft, 150, 145, "LAT: --- LNG: ---", TEXT_SIZE, TFT_BLACK, TFT_WHITE);
    getComponents()[MAPPING_TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TEXT_SIZE, TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[MAPPING_TEXT_WAIT])->setHide(true);
}

void MappingFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool MappingFrame::touchScreenEvent(int x, int y) {
    MappingFrameComponents selected = getComponentForTouch(x, y);

    if(selected == TO_MAIN_SCREEN_MAPPING) {
        ((TextBase*) getComponents()[MAPPING_TEXT_WAIT])->setHide(false);
        getComponents()[MAPPING_TEXT_WAIT]->draw();
        myLCDScreen.setCurrentFrame(MAIN_SCREEN);
        ((TextBase*) getComponents()[MAPPING_TEXT_WAIT])->setHide(true);
        return true;   
    }
    return false;
}

void MappingFrame::loop() {
    updateCoordinatesStatus();
    if(followBotManager.getCurrentControl() == MANUAL) {
        ((TextBase*) getComponents()[MAPPING_TEXT_WAIT])->setHide(false);
        getComponents()[MAPPING_TEXT_WAIT]->draw();
        myLCDScreen.setCurrentFrame(MANUAL_SCREEN);
        ((TextBase*) getComponents()[MAPPING_TEXT_WAIT])->setHide(true);
    } else if (followBotManager.getCurrentControl() == FOLLOWING) {
        ((TextBase*) getComponents()[MAPPING_TEXT_WAIT])->setHide(false);
        getComponents()[MAPPING_TEXT_WAIT]->draw();
        myLCDScreen.setCurrentFrame(FOLLOWING_SCREEN);
        ((TextBase*) getComponents()[MAPPING_TEXT_WAIT])->setHide(true);
    }
}

void MappingFrame::updateCoordinatesStatus() {
    unsigned long currentMillis = millis();

    // Only update every 1 second
    if (currentMillis - mLastCoordinatesCheckTime >= COORDINATES_CHECK_INTERVAL) {
        mLastCoordinatesCheckTime = currentMillis;

        String newCoordStatus = "LAT: " + String(followBotBluetooth.getMobileGPSData().lat) + " LNG: " + String(followBotBluetooth.getMobileGPSData().lon);

        // Only update display if value changes
        if (newCoordStatus != mLastCoordStatus) {
            mLastCoordStatus = newCoordStatus;
            ((TextBase*) getComponents()[FOLLOWING_TEXT_COORD])->setTextAndDraw(newCoordStatus);
        }
    }
    
}