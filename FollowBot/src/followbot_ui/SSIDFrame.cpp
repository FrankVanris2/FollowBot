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


//Universal Object
SSIDFrame ssidFrame;

void SSIDFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    comps[BACK_BUTTON] = new Button(tft, 5, 5, 120 , 40, "Back", 10);
    comps[SSID_INPUT_BOX] = new InputBox(tft, 140, 80, 200, 50, "", 2, TFT_BLACK);
    comps[SSID_TEXT] = new Text(tft, 140, 80, "Input SSID", 2, TFT_BLACK);

}

void SSIDFrame::draw() {
    getTFT().fillScreen(TFT_WHITE);
    for(auto& it: comps) {
        it.second->draw();
    }
}

bool SSIDFrame::touchScreenEvent(int x, int y) {
    return false;
}