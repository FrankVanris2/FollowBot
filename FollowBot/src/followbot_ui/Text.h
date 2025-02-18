/*
By: Frank Vanris
Date: 2/13/2025
Desc: Creating a Text class for the User to input text onto the screen at various sizes
*/

#pragma once
#include "Arduino.h"
#include "UIComponent.h"

class TFT_eSPI;

class Text : public UIComponent {
public:
    Text(TFT_eSPI& tft, int x, int y, const String& text, int text_size, int text_color);

    virtual void draw();

    void drawCenteredText(int screenWidth, int screenHeight);

protected:
    int getX() {
        return mX;
    }
    int getY() {
        return mY;
    }
    

private:
    int mX;
    int mY;
    String mText;
    int mTextSize;
    int mTextColor;

};