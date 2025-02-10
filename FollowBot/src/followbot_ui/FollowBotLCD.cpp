/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to ask user for ssid and password so that robot can connect to wireless network.
*/

#include "FollowBotLCD.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Arduino.h"
#include "Adafruit_ST7796S_kbv.h"
#include "TFT_Touch.h"



// Universal object
LCDScreen myLCDScreen;

// Can use Ardiuno pin references, arbitrary allocation, TFT_eSPI controls chip select
#define TFT_CS        10
#define TFT_DC         9
#define TFT_RST        8

#define TFT_SCLK      13
#define TFT_MISO      12
#define TFT_MOSI      11

//for touch
#define DCS     5
#define DCLK     6
#define DIN     4
#define DOUT    3

// Constructor
LCDScreen::LCDScreen() {}


Adafruit_ST7796S_kbv tft = Adafruit_ST7796S_kbv(TFT_CS, TFT_DC, TFT_RST);

#define HMIN 0
#define HMAX 3840
#define VMIN 0
#define VMAX 3840
#define XYSWAP 1 // 0 or 1

#define HRES 480 /* Default screen resolution for X axis */
#define VRES 320 /* Default screen resolution for Y axis */

TFT_Touch touch = TFT_Touch(DCS, DCLK, DIN, DOUT);

#define TEXT_SIZE 2

unsigned int X_RAW, Y_RAW;
int X_Coord, Y_Coord;

// Setup
void LCDScreen::myLCDScreen_Setup() {
  tft.begin(23900000);
  tft.setRotation(3);
  tft.fillScreen(ST7796S_WHITE);

  touch.setCal(HMIN, HMAX, VMIN, VMAX, HRES, VRES, XYSWAP);
  touch.setRotation(3);
  
  drawInputFields(140, 120, 200, 40, "SSID");
  drawInputFields(140, 180, 200, 40, "Password");



}

// Loop
void LCDScreen::myLCDScreen_Loop() {
  if (touch.Pressed()) {
    X_Coord = touch.X();
    Y_Coord = touch.Y();

    //Check if the touch is within the button area
    if (X_Coord > 140 && X_Coord < 340 && Y_Coord > 120 && Y_Coord < 160) {
      Serial.println("SSID Button Pressed");
    }
    if (X_Coord > 140 && X_Coord < 340 && Y_Coord > 180 && Y_Coord < 220) {
      Serial.println("Password Button Pressed");
    }
  }
}

void LCDScreen::drawInputFields(int x, int y, int width, int height, const char* label) {
  tft.fillRect(x, y, width, height, ST7796S_BLACK);
  tft.setTextColor(ST7796S_WHITE);
  tft.setTextSize(3);
  tft.setCursor(x + 10, y + 10);
  tft.print(label);
}
