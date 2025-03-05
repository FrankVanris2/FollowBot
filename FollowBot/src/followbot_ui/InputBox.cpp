/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a input box where the user will be able to input text when it comes to ssid and password info
*/

#include <TFT_eSPI.h>
#include "InputBox.h"

const int PADDING = 5; // pixels

InputBox::InputBox(TFT_eSPI& tft, int x, int y, int width, const String& text, int text_size, int text_color, int backgroundColor) : 
TextBase(tft, x + PADDING, y + PADDING, text, text_size, text_color, backgroundColor),
mX(x), mY(y), mWidth(width), mLastTimeClicked(0) {
    setTFT(tft);
    int fontHeight = tft.fontHeight(1);
    mHeight = fontHeight * text_size + 2 * PADDING;
}

void InputBox::draw() {
    getTFT().drawRect(mX, mY, mWidth, mHeight, TFT_BLACK);
    TextBase::draw();
}

bool InputBox::touchScreenEvent(int x, int y) {
    unsigned int currentTime = millis();
    if (currentTime - mLastTimeClicked < 200) {
        return false;
    }
    mLastTimeClicked = currentTime;

    return (x > mX && x < mX + mWidth && y > mY && y < mY + mHeight);
}
