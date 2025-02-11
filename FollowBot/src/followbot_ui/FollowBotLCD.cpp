/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to ask user for ssid and password so that robot can connect to wireless network.
*/

#include "FollowBotLCD.h"
#include "SPI.h"
#include "Arduino.h"
#include "Display_Setup.h"
#include "Adafruit_ST7796S_kbv.h"
#include "Adafruit_GFX.h"
#include "TFT_Touch.h"


#define TEXT_SIZE 2


// Universal object
LCDScreen myLCDScreen;



// Constructor
LCDScreen::LCDScreen() {}


Adafruit_ST7796S_kbv tft = Adafruit_ST7796S_kbv(TFT_CS, TFT_DC, TFT_RST);
TFT_Touch touch = TFT_Touch(DCS, DCLK, DIN, DOUT);





// Setup
void LCDScreen::myLCDScreen_Setup() {
  tft.begin(SPI_FREQUENCY);
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
      // inputting ssid information through a text prompt
      Serial.println("SSID Button Pressed");
    }
    if (X_Coord > 140 && X_Coord < 340 && Y_Coord > 180 && Y_Coord < 220) {
      // inputting passsword information through a text prompt
      Serial.println("Password Button Pressed");
    }
  }
}

void LCDScreen::drawInputFields(int x, int y, int width, int height, const char* label) {
  tft.fillRect(x, y, width, height, ST7796S_BLACK);

  tft.setTextSize(3);
  tft.setTextColor(ST7796S_WHITE);
  std::array<int, 2> text_centered = centerText(x, y, width, height);
  tft.setCursor(text_centered[0], text_centered[1]);
  tft.print(label);
}

std::array<int, 2> LCDScreen::centerText(int x, int y, int width, int height) {
  int16_t x1, y1;
  uint16_t w, h;
  tft.getTextBounds("SSID", 0, 0, &x1, &y1, &w, &h);

  return std::array<int, 2>({x + (width - w) / 2, y + (height - h) / 2});
}

