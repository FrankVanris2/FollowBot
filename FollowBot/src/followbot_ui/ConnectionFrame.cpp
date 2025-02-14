/*
By: Frank Vanris
Date: 2/11/2025
Desc: Creating a Connection Frame 
*/

#include "ConnectionFrame.h"
#include "TFT_eSPI.h"
#include "Button.h"
#include "Text.h"
#include "FollowBotLCD.h"
#include "ScreenState.h"

//Universal object
ConnectionFrame connectionFrame;

void ConnectionFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    connectionStatusText = new Text(tft, 130, 122, "Connected", 5, TFT_BLACK);
    btnBack = new Button(tft, 200, 240 , 120, 40, "Back", 10);
}

void ConnectionFrame::drawScreen() {
    getTFT().fillScreen(TFT_WHITE);
    //connectionStatusText->drawCenteredText(getTFT().width(), getTFT().height()); (Work on in the near future)
    connectionStatusText->drawText();
    btnBack->drawButton();

}

void ConnectionFrame::touchScreenEvent(int x, int y) {
    if (btnBack->touchScreenEvent(x, y)) {
        myLCDScreen.setCurrentFrame(MAIN_SCREEN);
        return;
    }

}