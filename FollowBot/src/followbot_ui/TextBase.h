/*
By: Frank Vanris
Date: 2/21/2025
Desc: Creating a Text base class
*/

#pragma once
#include "Arduino.h"
#include "UIComponent.h"
#include "TFT_eSPI.h"

const int BASE_FONT_WIDTH = 6; // pixels
const int BASE_FONT_HEIGHT = 8; // pixels

class TextBase: public UIComponent{

public:
    TextBase(TFT_eSPI& tft, const String& text = "", int color = TFT_BLACK, int backgroundColor = TFT_WHITE) :
    TextBase(tft, 0, 0, text, color, backgroundColor)
    {}

    TextBase(TFT_eSPI& tft, int xText, int yText, const String& text = "", int color = TFT_BLACK, int backgroundColor = TFT_WHITE);

    void setTextPosition(int xText, int yText) {
        mXText = xText;
        mYText = yText;
    }

    void setText(const String& text) {
        mText = text;
    }

    const String& getText() const {
        return mText;
    }
 
    virtual void draw();

    void setTextAndDraw(const String& text); 

    void setCentered(bool centered) {
        mIsCentered = centered;
    }

    void setHide(bool hide) {
        mHide = hide;
    }

private:
    bool mIsCentered;
    int mXText;
    int mYText;
    String mText;
    int mColor;
    int mBackgroundColor;
    bool mHide;

    const int TEXT_SIZE = 2;
};