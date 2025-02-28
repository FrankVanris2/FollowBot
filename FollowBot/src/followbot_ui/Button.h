/*
By: Frank Vanris
Date: 2/11/2025
Desc: Creating a button class which allows you as a developer to create buttons easily
*/

#pragma once
#include <Arduino.h>

#include "UIComponent.h"
#include "TextBase.h"

class TFT_eSPI;

class Button : public TextBase {
public:
    Button(TFT_eSPI& tft, int x, int y, int w, int h,  const String& label, int radius = 0);

    virtual void draw();
    virtual bool touchScreenEvent(int x, int y);

private:
    int mX;
    int mY;
    int mW;
    int mH;
    String mLabel;
    int mRadius;

    unsigned int mLastTimeClicked;

};