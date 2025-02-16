/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a input box where the user will be able to input text when it comes to ssid and password info
*/

#include "InputBox.h"
#include "TFT_eSPI.h"


InputBox::InputBox(TFT_eSPI& tft, int x, int y, int width, int height, const String& text, int text_size, int text_color) : 
Text(tft, x, y, text, text_size, text_color), mWidth(width), mHeight(height) {
}

void InputBox::draw() {

    getTFT().drawRect(getX(), getY(), mWidth, mHeight, TFT_BLACK);
    Text::draw();
}