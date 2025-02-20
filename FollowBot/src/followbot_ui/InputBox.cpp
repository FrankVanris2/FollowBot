/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a input box where the user will be able to input text when it comes to ssid and password info
*/

#include "InputBox.h"
#include "TFT_eSPI.h"
#include "Text.h"


InputBox::InputBox(TFT_eSPI& tft, int x, int y, int width, int height, const String& text, int text_size, int text_color) : 
mX(x), mY(y), mWidth(width), mHeight(height), mText(text), 
mTextSize(text_size), mTextColor(text_color), mLastTimeClicked(0) {
    setTFT(tft);
    Text* textObj = new Text(getTFT(), x, y, text, text_size, text_color);
}

void InputBox::draw() {

    getTFT().drawRect(mX, mY, mWidth, mHeight, TFT_BLACK);
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