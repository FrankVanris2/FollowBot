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
// Universal object
LCDScreen myLCDScreen;

// Setup
void LCDScreen::myLCDScreen_Setup() {
  mainFrame.setup(tft);

  tft.begin();
  tft.setRotation(3);
  setCurrentFrame(MAIN_SCREEN);

}

// Loop
void LCDScreen::myLCDScreen_Loop() {
  uint16_t x= 0, y = 0;
  bool pressed = tft.getTouch(&x, &y);

  if (pressed) {
    mCurrentFrame->touchScreenEvent(x, y);
    
  }
}

void LCDScreen::setCurrentFrame(ScreenFrames newFrame) {
  Serial.print("LCDScreen::setCurrentFrame, newFrame: ");
  Serial.println(newFrame);

  switch (newFrame) {
    case MAIN_SCREEN: mCurrentFrame = &mainFrame; break;
    case SSID_SCREEN: break;
    case PASSWORD_SCREEN: break;
    default:
      Serial.print('LCDScreen::setCurrentFrame(), unknown Frame: ');
      Serial.println(newFrame);
      return;
  }

  mCurrentFrame->draw();
}
