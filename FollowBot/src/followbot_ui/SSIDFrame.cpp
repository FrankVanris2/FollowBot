/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a SSID screen where user inputs ssid info and it gets stored in the EEPROM
*/


#include "SSIDFrame.h"
#include "TFT_eSPI.h"
#include "Button.h"
#include "Text.h"
#include "InputBox.h"
#include "ScreenState.h"
#include "FollowBotLCD.h"


//Universal Object
SSIDFrame ssidFrame;

void SSIDFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[BACK_BUTTON] = new Button(tft, 5, 5, 60 , 40, "<--", 10);
    getComponents()[SSID_TEXT] = new Text(tft, 50, 85, "Input SSID:", 2, TFT_BLACK);
    getComponents()[SSID_INPUT_BOX] = new InputBox(tft, 200, 82, 200, 30, "input box", 2, TFT_BLACK);
    

}

void SSIDFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool SSIDFrame::touchScreenEvent(int x, int y) {
    SSIDFrameComponents selected = getComponentForTouch(x, y);
    switch(selected) {
        case BACK_BUTTON:
            Serial.println("Back button pressed");
            myLCDScreen.setCurrentFrame(MAIN_SCREEN);
            return true;

        case SSID_INPUT_BOX:
            Serial.println("Input box pressed");
            myLCDScreen.setCurrentFrame(KEYBOARD_SCREEN);
            return true;
    }
    return false;
}