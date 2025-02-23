/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a SSID screen where user inputs ssid info and it gets stored in the EEPROM
*/


#include "SSIDFrame.h"
#include "TFT_eSPI.h"
#include "Button.h"
#include "InputBox.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"
#include "TextBase.h"


//Universal Object
SSIDFrame ssidFrame;

void SSIDFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[BACK_BUTTON] = new Button(tft, 5, 5, 60 , 40, "<--", 10);
    getComponents()[SSID_TEXT] = new TextBase(tft, 50, 87, "Input SSID:");
    getComponents()[SSID_INPUT_BOX] = new InputBox(tft, 200, 80, 200, "input box", 2, TFT_BLACK);
    getComponents()[SSID_TEXT_WAIT] = new TextBase(tft, 5, 300, "Wait", TFT_WHITE, TFT_RED);
    ((TextBase*) getComponents()[SSID_TEXT_WAIT])->setHide(true);
}

void SSIDFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool SSIDFrame::touchScreenEvent(int x, int y) {
    SSIDFrameComponents selected = getComponentForTouch(x, y);
    switch(selected) {
        case BACK_BUTTON:
            Serial.println("SSID Back button pressed");
            ((TextBase*) getComponents()[SSID_TEXT_WAIT])->setHide(false);
            getComponents()[SSID_TEXT_WAIT]->draw();
            myLCDScreen.setCurrentFrame(MAIN_SCREEN);
            ((TextBase*) getComponents()[SSID_TEXT_WAIT])->setHide(true);
            return true;

        case SSID_INPUT_BOX:
            Serial.println("Input box pressed");
            ((TextBase*) getComponents()[SSID_TEXT_WAIT])->setHide(false);
            getComponents()[SSID_TEXT_WAIT]->draw();
            myLCDScreen.setCurrentFrame(KEYBOARD_SCREEN);
            ((TextBase*) getComponents()[SSID_TEXT_WAIT])->setHide(true);
            return true;
    }
    return false;
}