/*
By: Frank Vanris
Date: 2/13/2025
Desc: Creating a Text class for the User to input text onto the screen at various sizes
*/

#pragma once
#include "Arduino.h"

class TFT_eSPI;

class Text {
public:
    Text(TFT_eSPI& tft, int x, int y, const String& text, int text_size, int text_color);

    void drawText();

    void drawCenteredText(int screenWidth, int screenHeight);

private:
    TFT_eSPI& mTFT;
    int mX;
    int mY;
    String mText;
    int mTextSize;
    int mTextColor;

};