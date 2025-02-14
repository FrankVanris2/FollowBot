/*
By: Frank Vanris
Date: 2/11/2025
Desc: Creating a button class which allows you as a developer to create buttons easily
*/

#pragma once
#include "Arduino.h"

class TFT_eSPI;

class Button {
public:
    Button(TFT_eSPI& tft, int x, int y, int w, int h,  const String& label, int radius = 0);

    void drawButton();

    bool touchScreenEvent(int x, int y);

private:
    const int TEXT_SIZE = 2;

    TFT_eSPI& mTFT; 
    int mX;
    int mY;
    int mW;
    int mH;
    String mLabel;
    int mRadius;

    unsigned int mLastTimeClicked;

};