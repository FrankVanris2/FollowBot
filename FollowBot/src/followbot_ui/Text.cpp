/*
By: Frank Vanris
Date: 2/13/2025
Desc: Making Text easier for the user to use
*/

#include "Text.h"
#include "TFT_eSPI.h"

Text::Text(TFT_eSPI& tft, int x, int y, const String& text, int text_size, int text_color) : 
    mTFT(tft), mX(x), mY(y), 
    mText(text), mTextSize(text_size), 
    mTextColor(text_color) {

}


void Text::drawText() {
    mTFT.setTextColor(mTextColor);
    mTFT.setTextSize(mTextSize);
    mTFT.setCursor(mX, mY);
    mTFT.print(mText);
}


//NOTE: This needs to be worked on (Currently text is not being centered)
void Text::drawCenteredText(int screenWidth, int screenHeight) {
    int16_t textWidth = mTFT.textWidth(mText.c_str());
    int16_t textHeight = mTFT.fontHeight();
    
    int16_t x = (screenWidth - textWidth) / 2;
    int16_t y = (screenHeight - textHeight) / 2;
    
    mTFT.setTextColor(mTextColor);
    mTFT.setTextSize(mTextSize);
    mTFT.setCursor(x, y);
    Serial.println("Printed Text");
    mTFT.print(mText);

    // Debugging output to check calculated positions
    Serial.print("Text Width: "); Serial.println(textWidth);
    Serial.print("Text Height: "); Serial.println(textHeight);
    Serial.print("X Position: "); Serial.println(x);
    Serial.print("Y Position: "); Serial.println(y);
}