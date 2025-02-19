/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a keyboard
*/

#include "Keyboard.h"
#include "TFT_eSPI.h"
#include "Button.h"
#include "InputBox.h"
#include "FollowBotLCD.h"


Keyboard keyboard;

void Keyboard::setup(TFT_eSPI& tft) {
    setTFT(tft);
    getComponents()[KBD_BACK_BUTTON] = new Button(tft, 5, 5, 60 , 40, "<--", 10);
    getComponents()[KBD_INPUT_BOX] = new InputBox(tft, 140, 72, 200, 30, "input box", 2, TFT_BLACK);
    
    getComponents()[KBD_NUMBER_1] = new Button(tft, 42, 122, 36, 36, "1", 1);
    getComponents()[KBD_NUMBER_2] = new Button(tft, 82, 122, 36, 36, "2", 1);
}

void Keyboard::draw() {
    getTFT().fillScreen(TFT_WHITE);
    drawComponents();
}

bool Keyboard::touchScreenEvent(int x, int y) {
    KeyboardButtons selected = getComponentForTouch(x, y);

    switch(selected) {
        case KBD_BACK_BUTTON:
            Serial.println("Back button pressed");
            myLCDScreen.setCurrentFrame(SSID_SCREEN);
            return true;

        case KBD_NUMBER_1: 
            Serial.println("button 1 pressed"); 
            return true;

        case KBD_NUMBER_2: 
            Serial.println("button 2 pressed"); 
            return true;
    }
    return false;
}