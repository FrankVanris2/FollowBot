/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a input box where the user will be able to input text when it comes to ssid and password info
*/

#include "InputBox.h"
#include "TFT_eSPI.h"
#include "Text.h"

const int PADDING = 5; // pixels

InputBox::InputBox(TFT_eSPI& tft, int x, int y, int width, const String& text, int text_size, int text_color) : 
mX(x), mY(y), mWidth(width), mText(text), 
mTextSize(text_size), mTextColor(text_color), mLastTimeClicked(0) {
    setTFT(tft);
    getTFT().setTextSize(text_size);
    int fontHeight = tft.fontHeight(1);
    mHeight = fontHeight + 2 * PADDING;
    Serial.println(String("fontHeight = ") + fontHeight + ", mHeight = " + mHeight);
}

void InputBox::draw() {

    Serial.println(String("mX = ") + mX + ", my = " + mY + ", mHeight = " + mHeight);
    getTFT().drawRect(mX, mY, mWidth, mHeight, TFT_BLACK);
    getTFT().setTextColor(mTextColor);
    getTFT().setTextSize(mTextSize);
    getTFT().setCursor(mX + PADDING, mY + PADDING);
    Serial.println(String("text mX = ") + (mX + PADDING) + ", my = " + (mY + PADDING));
    getTFT().print(mText);
}

bool InputBox::touchScreenEvent(int x, int y) {
    unsigned int currentTime = millis();
    if (currentTime - mLastTimeClicked < 200) {
        return false;
    }
    mLastTimeClicked = currentTime;
    Serial.print("inputBox: ("); 
    Serial.print(mX);
    Serial.print(", ");
    Serial.print(mY);
    Serial.print("), width: ");
    Serial.print(mWidth);
    Serial.print(", height: ");
    Serial.println(mHeight);

    return (x > mX && x < mX + mWidth && y > mY && y < mY + mHeight);
}