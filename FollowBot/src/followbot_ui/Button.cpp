/*
By: Frank Vanris
Date: 2/10/2025
Desc: Creating a button class that I can use to easily make buttons onto the screen
*/

#include "Button.h"
#include "followbot_ui/TextBounds.h"


//Universal obect
Button button;


//Constructors
Button::Button() : tftRef(nullptr) {}

Button::Button(Adafruit_ST7796S_kbv& tftInstance) : tftRef(&tftInstance) {}

void Button::drawButton(int x, int y, int width, int height, const char* label) {
    tftRef->fillRect(x, y, width, height, ST7796S_BLACK);
  
    tftRef->setTextSize(3);
    tftRef->setTextColor(ST7796S_WHITE);
    std::array<int, 2> text_centered = textBounds.centerText(x, y, width, height);
    tftRef->setCursor(text_centered[0], text_centered[1]);
    tftRef->print(label);
  }