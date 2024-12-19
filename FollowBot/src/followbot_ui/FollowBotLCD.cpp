/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to ask user for ssid and password so that robot can connect to wireless network.
*/

#include "FollowBotLCD.h"
#include "Arduino.h"
#include <TFT_eSPI.h>

#define BUTTON_X 60
#define BUTTON_Y 100
#define BUTTON_W 100
#define BUTTON_H 50
#define BUTTON_TEXT "Press Me"

// Universal object
LCDScreen myLCDScreen;

TFT_eSPI tft = TFT_eSPI(); // creating an instance of the library


// Constructor
LCDScreen::LCDScreen() {}


// Testing purposes
void LCDScreen::printHello() {
    Serial.println("initializing TFT");
    tft.init();
    //tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    //tft.setTextColor(TFT_WHITE);
    //tft.drawString("Hello World", 10, 10, 2);
}

// Setup
void LCDScreen::myLCDScreen_Setup() {
    tft.init();
    tft.setRotation(1); // Set the rotation if needed
    tft.fillScreen(TFT_BLACK); // Clear the screen

    // Draw the button
    tft.fillRect(BUTTON_X, BUTTON_Y, BUTTON_W, BUTTON_H, TFT_BLUE);
    tft.setTextColor(TFT_WHITE);
    tft.drawString(BUTTON_TEXT, BUTTON_X + 10, BUTTON_Y + 15, 2);
}

// Loop
void LCDScreen::myLCDScreen_Loop() {
    uint16_t x, y;
    if (tft.getTouch(&x, &y)) {
        if (x > BUTTON_X && x < BUTTON_X + BUTTON_W && y > BUTTON_Y && y < BUTTON_Y + BUTTON_H) {
            // Button pressed
            tft.fillRect(BUTTON_X, BUTTON_Y, BUTTON_W, BUTTON_H, TFT_RED);
            tft.drawString("Pressed", BUTTON_X + 10, BUTTON_Y + 15, 2);
            delay(500); // Debounce delay
            tft.fillRect(BUTTON_X, BUTTON_Y, BUTTON_W, BUTTON_H, TFT_BLUE);
            tft.drawString(BUTTON_TEXT, BUTTON_X + 10, BUTTON_Y + 15, 2);
        }
    }
}
