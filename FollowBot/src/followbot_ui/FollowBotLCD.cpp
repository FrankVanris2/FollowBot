/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to ask user for ssid and password so that robot can connect to wireless network.
*/

#include "FollowBotLCD.h"
#include "SPI.h"
#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "MainFrame.h"
#include "ConnectionFrame.h"


#define TEXT_SIZE 2


// Universal object
LCDScreen myLCDScreen;

// Constructor
LCDScreen::LCDScreen() {}

// Setup
void LCDScreen::myLCDScreen_Setup() {
  mainFrame.setup(tft);
  //connectionFrame.setup(tft);
  //disconnectionFrame.setup(tft);


  // Initialise the TFT screen
  tft.begin();
  tft.setRotation(3);
  
  mainFrame.drawScreen();
  //setFrame(enum);

}

// Loop
void LCDScreen::myLCDScreen_Loop() {
  uint16_t x= 0, y = 0;
  bool pressed = tft.getTouch(&x, &y);

  if (pressed) {
    mainFrame.touchScreenEvent(x, y);
  }
}











