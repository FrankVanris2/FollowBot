/*
By: Frank Vanris
Date: 2/11/2025
Desc: Creating a button class which allows you as a developer to create buttons easily
*/

#pragma once
#include "Arduino.h"
#include "UIComponent.h"

class TFT_eSPI;

class Button : public UIComponent {
public:
    Button(TFT_eSPI& tft, int x, int y, int w, int h,  const String& label, int radius = 0);
    Button(const Button& original);
    Button& operator=(const Button& rhs);

    virtual void draw();
    virtual bool touchScreenEvent(int x, int y);

private:
    const int TEXT_SIZE = 2;

    int mX;
    int mY;
    int mW;
    int mH;
    String mLabel;
    int mRadius;

    unsigned int mLastTimeClicked;

};