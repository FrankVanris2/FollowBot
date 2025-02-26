/*
By: Frank Vanris
Date: 2/11/2025
Desc: Making button making easy for the user
*/

#include "Button.h"
#include "TFT_eSPI.h"



Button::Button(TFT_eSPI& tft, int x, int y, int w, int h, const String& label, int radius) : 
TextBase(tft, label, TEXT_SIZE, TFT_WHITE, TFT_BLACK),
mX(x), mY(y), 
mW(w), mH(h), mLabel(label), 
mRadius(radius), mLastTimeClicked(0) {
    int xText = mX + (mW / 2);
    int yText = mY + (mH / 2 - (BASE_FONT_HEIGHT * TEXT_SIZE) / 2);
    setTextPosition(xText, yText);
    setCentered(true);
}


void Button::draw(){

    if (mRadius == 0) {
        getTFT().fillRect(mX, mY, mW, mH, TFT_BLACK);
    } else {
        getTFT().fillRoundRect(mX, mY, mW, mH, mRadius, TFT_BLACK);
    }
    TextBase::draw();    
}

bool Button::touchScreenEvent(int x, int y) {
    unsigned int currentTime = millis();
    if (currentTime - mLastTimeClicked < 200) {
        return false;
    }
    mLastTimeClicked = currentTime;
    return (x > mX && x < mX + mW && y > mY && y < mY + mH);
}


