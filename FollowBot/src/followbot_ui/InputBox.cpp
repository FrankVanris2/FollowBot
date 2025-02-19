/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a input box where the user will be able to input text when it comes to ssid and password info
*/

#include "InputBox.h"
#include "TFT_eSPI.h"


InputBox::InputBox(TFT_eSPI& tft, int x, int y, int width, int height, const String& text, int text_size, int text_color) : 
Text(tft, x, y, text, text_size, text_color), mWidth(width), mHeight(height), mLastTimeClicked(0) {
}

void InputBox::draw() {

    getTFT().drawRect(getX() - 5, getY() - 7, mWidth, mHeight, TFT_BLACK);
    Text::draw();
}

bool InputBox::touchScreenEvent(int x, int y) {
    unsigned int currentTime = millis();
    if (currentTime - mLastTimeClicked < 200) {
        return false;
    }
    mLastTimeClicked = currentTime;
    Serial.print("inputBox: ("); 
    Serial.print(getX());
    Serial.print(", ");
    Serial.print(getY());
    Serial.print("), width: ");
    Serial.print(mWidth);
    Serial.print(", height: ");
    Serial.println(mHeight);

    return (x > getX() && x < getX() + mWidth && y > getY() && y < getY() + mHeight);
}