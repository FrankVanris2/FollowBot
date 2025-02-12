/*
By: Frank Vanris
Date 2/11/2025
Desc: Creating the Main frame*/


#include "MainFrame.h"
#include "TFT_eSPI.h"
#include "Button.h"



//Universal Object
MainFrame mainFrame;


void MainFrame::setup(TFT_eSPI& tft) {
    setTFT(tft);
    btnSSID = new Button(tft, 140, 80, 200, 50, "SSID", 10);
    btnPassword = new Button(tft, 140, 160, 200, 50, "Password", 10);
    btnConnect = new Button(tft, 180, 240, 120, 40, "Connect", 10);

}


void MainFrame::drawScreen() {
    getTFT().fillScreen(TFT_WHITE);
    btnSSID->drawButton();
    btnPassword->drawButton();
    btnConnect->drawButton();
}

void MainFrame::touchScreenEvent(int x, int y) {
    if (btnSSID->touchScreenEvent(x, y)) {
        Serial.println("SSID button pressed");
        return;
    }

    if (btnPassword->touchScreenEvent(x, y)) {
        Serial.println("Password button pressed");
        return;
    }

    if (btnConnect->touchScreenEvent(x, y)) {
        Serial.println("Connect button pressed");
        return;
    }
}