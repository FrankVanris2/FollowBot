/*
By: Frank Vanris
Date: 2/11/2025
Desc: Making button making easy for the user
*/

#include "Button.h"

#include "TFT_eSPI.h"

Button::Button(TFT_eSPI& tft, int x, int y, int w, int h,  const String& label, int radius) : 
mTFT(tft), mX(x), mY(y), 
mW(w), mH(h), mLabel(label), 
mRadius(radius), mLastTimeClicked(0) {}




void Button::drawButton(){

    if (mRadius == 0) {
        mTFT.fillRect(mX, mY, mW, mH, TFT_BLACK);
    } else {
        mTFT.fillRoundRect(mX, mY, mW, mH, mRadius, TFT_BLACK);
    }
    
    mTFT.setTextColor(TFT_WHITE);
    mTFT.setTextSize(TEXT_SIZE);

    //Calculate text size manually
    int16_t cursorX = mX + (mW - mLabel.length() * 6 * TEXT_SIZE) / 2;
    int16_t cursorY = mY + (mH - 8 * TEXT_SIZE) / 2;
    
    mTFT.setCursor(cursorX, cursorY);
    mTFT.print(mLabel);
}


bool Button::touchScreenEvent(int x, int y) {
    unsigned int currentTime = millis();
    if (currentTime - mLastTimeClicked < 200) {
        return false;
    }
    mLastTimeClicked = currentTime;
    return (x > mX && x < mX + mW && y > mY && y < mY + mH);
}

