/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating an input box for the user to put input
*/

#pragma once
#include "UIComponent.h"
#include "Arduino.h"

class InputBox: public UIComponent{

public:

    InputBox(TFT_eSPI& tft, int x, int y, int width, const String& text, int text_size, int text_color);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);
private:
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    String mText;
    int mTextSize;
    int mTextColor; 

    unsigned int mLastTimeClicked;

};