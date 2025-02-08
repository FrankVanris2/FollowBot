/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to ask user for ssid and password so that robot can connect to wireless network.
*/

#include "FollowBotLCD.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ST7796S_kbv.h"
#include "Arduino.h"

// Universal object
LCDScreen myLCDScreen;

#define TFT_CS        10
#define TFT_DC         9
#define TFT_RST        8
#define TFT_SDA       11
#define TFT_CLK       13
#define TFT_MISO      12

Adafruit_ST7796S_kbv tft = Adafruit_ST7796S_kbv(TFT_CS, TFT_DC, TFT_RST);

#define DOUT 3 /* Data out pin (T_DO) of touch screen */
#define DIN 4 /* Data in pin (T_DIN) of touch screen */
#define DCS 5 /* Chip select pin (T_CS) of touch screen */
#define DCLK 6 /* Clock pin (T_CLK) of touch screen */






// Constructor
LCDScreen::LCDScreen() {}


// Testing purposes
void LCDScreen::printHello() {

}

// Setup
void LCDScreen::myLCDScreen_Setup() {

}

// Loop
void LCDScreen::myLCDScreen_Loop() {

}
