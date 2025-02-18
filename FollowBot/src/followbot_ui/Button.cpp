/*
By: Frank Vanris
Date: 2/11/2025
Desc: Making button making easy for the user
*/

#include "Button.h"
#include "TFT_eSPI.h"

Button::Button(TFT_eSPI& tft, int x, int y, int w, int h,  const String& label, int radius) : 
mX(x), mY(y), 
mW(w), mH(h), mLabel(label), 
mRadius(radius), mLastTimeClicked(0) {
    setTFT(tft);
}

Button::Button(const Button& original) : 
mX(original.mX), mY(original.mY), 
mW(original.mW), mH(original.mH), mLabel(original.mLabel), 
mRadius(original.mRadius), mLastTimeClicked(original.mLastTimeClicked)
{
    setTFT(original.getTFT());
}

Button& Button::operator=(const Button& rhs) {
    if(this == &rhs) {
        return *this;
    }

    mX = rhs.mX; 
    mY = rhs.mY;
    mW = rhs.mW; 
    mH = rhs.mH;
    mLabel = rhs.mLabel; 
    mRadius = rhs.mRadius; 
    mLastTimeClicked = rhs.mLastTimeClicked;

    return *this;
}

void Button::draw(){

    if (mRadius == 0) {
        getTFT().fillRect(mX, mY, mW, mH, TFT_BLACK);
    } else {
        getTFT().fillRoundRect(mX, mY, mW, mH, mRadius, TFT_BLACK);
    }
    
    getTFT().setTextColor(TFT_WHITE);
    getTFT().setTextSize(TEXT_SIZE);

    //Calculate text size manually
    int16_t cursorX = mX + (mW - mLabel.length() * 6 * TEXT_SIZE) / 2;
    int16_t cursorY = mY + (mH - 8 * TEXT_SIZE) / 2;
    
    getTFT().setCursor(cursorX, cursorY);
    getTFT().print(mLabel);
}

bool Button::touchScreenEvent(int x, int y) {
    unsigned int currentTime = millis();
    if (currentTime - mLastTimeClicked < 200) {
        return false;
    }
    mLastTimeClicked = currentTime;
    return (x > mX && x < mX + mW && y > mY && y < mY + mH);
}

