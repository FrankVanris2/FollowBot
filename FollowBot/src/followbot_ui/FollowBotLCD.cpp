/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to ask user for ssid and password so that robot can connect to wireless network.
*/

#include <SPI.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>

#include "FollowBotLCD.h"
#include "MainFrame.h"
#include "WiFiCredentials.h"
#include "Keyboard.h"

// Universal object
LCDScreen myLCDScreen;

// Setup
void LCDScreen::myLCDScreen_Setup() {
  mainFrame.setup(tft);
  wifiCredentials.setup(tft);
  keyboard.setup(tft);

  tft.begin();
  tft.setRotation(3);
  setCurrentFrame(MAIN_SCREEN);
  mainFrame.wifiClientSetup();
}

// Loop
void LCDScreen::myLCDScreen_Loop() {
  uint16_t x= 0, y = 0;
  bool pressed = tft.getTouch(&x, &y);

  if (pressed) {
    x = SCREEN_WIDTH - x;
    Serial.println();
    Serial.print("Pressed: ("); 
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.println(")");
    mCurrentFrame->touchScreenEvent(x, y);
  }

  // Call the current frame's loop method
  mCurrentFrame->loop();
}

void LCDScreen::setCurrentFrame(ScreenFrames newFrame) {
  Serial.print("LCDScreen::setCurrentFrame, newFrame: ");
  Serial.println(newFrame);
  
  switch (newFrame) {
    case MAIN_SCREEN: mCurrentFrame = &mainFrame; break;
    case WIFI_CREDENTIALS_SCREEN: mCurrentFrame = &wifiCredentials; break;
    case KEYBOARD_SCREEN: mCurrentFrame = &keyboard; break;
    default:
      Serial.print('LCDScreen::setCurrentFrame(), unknown Frame: ');
      Serial.println(newFrame);
      return;
  }

  mCurrentFrame->draw();
}
