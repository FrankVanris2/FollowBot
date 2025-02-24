/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating an input box for the user to put input
*/

#pragma once
#include "TextBase.h"
#include "Arduino.h"

class InputBox: public TextBase {

public:

    InputBox(TFT_eSPI& tft, int x, int y, int width, const String& text = "", int text_size = TEXT_SIZE, int text_color = TFT_BLACK, int backgroundColor = TFT_WHITE);
    virtual void draw();
    virtual bool touchScreenEvent(int x, int y);    

private:
    int mX, mY, mWidth, mHeight;
    unsigned int mLastTimeClicked;
};