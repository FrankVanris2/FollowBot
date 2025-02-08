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

#define DOUT A0 /* Data out pin (T_DO) of touch screen */ //3
#define DIN A2 /* Data in pin (T_DIN) of touch screen */ //4
#define DCS 5 /* Chip select pin (T_CS) of touch screen */
#define DCLK 6 /* Clock pin (T_CLK) of touch screen */

#define HMIN 0
#define HMAX 3840
#define VMIN 0
#define VMAX 3840
#define XYSWAP 1 // 0 or 1

#define HRES 480 /* Default screen resolution for X axis */
#define VRES 320 /* Default screen resolution for Y axis */


//#include <TFT_Touch.h>

#define TEXT_SIZE 2


// Constructor
LCDScreen::LCDScreen() {}



// Setup
void LCDScreen::myLCDScreen_Setup() {
    tft.begin(8000000);
 

  
  tft.setRotation(3);
  tft.startWrite();
  tft.fillScreen(ST7796S_YELLOW);
  tft.drawRect(100, 100, 200, 200 , ST7796S_RED);
  tft.endWrite();
  Serial.println("Setup complete");
  
}

// Loop
void LCDScreen::myLCDScreen_Loop() {
  tft.fillScreen(ST7796S_BLUE);
  delay(1000);
  tft.fillScreen(ST7796S_RED);
  delay(1000);
  tft.fillScreen(ST7796S_GREEN);
  delay(1000);
}
