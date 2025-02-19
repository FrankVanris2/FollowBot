/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating an input box for the user to put input
*/

#pragma once
#include "Text.h"

class InputBox: public Text{

public:

    InputBox(TFT_eSPI& tft, int x, int y, int width, int height, const String& text, int text_size, int text_color);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);
private:
    int mWidth;
    int mHeight;
    unsigned int mLastTimeClicked;

};