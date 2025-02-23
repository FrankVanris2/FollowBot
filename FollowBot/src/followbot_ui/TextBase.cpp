/*
By: Frank Vanris
Date: 2/21/2025
Desc: Creating a text base class for text purposes
*/


#include "TextBase.h"

TextBase::TextBase(TFT_eSPI& tft, int xText, int yText, const String& text, int color, int backgroundColor):
mXText(xText), mYText(yText), mText(text), mColor(color), mBackgroundColor(backgroundColor), mHide(false), mIsCentered(false) {
    setTFT(tft);
}

void TextBase::setTextAndDraw(const String& text) {
    mText = text;
    TextBase::draw();
}

void TextBase::draw() {
    if (mHide) return;
    getTFT().setTextColor(mColor);
    getTFT().setTextSize(TEXT_SIZE);
    if(mIsCentered) {
        //Centering reference:
        uint16_t mXTextCentered = mXText - (mText.length() * BASE_FONT_WIDTH * TEXT_SIZE / 2);
        getTFT().fillRect(mXTextCentered - 1, mYText - 1, mText.length() * BASE_FONT_WIDTH * TEXT_SIZE + 2, BASE_FONT_HEIGHT * TEXT_SIZE + 2, mBackgroundColor);
        getTFT().setCursor(mXTextCentered, mYText);
        getTFT().print(mText);
    } else {
        getTFT().fillRect(mXText - 1, mYText - 1, mText.length() * BASE_FONT_WIDTH * TEXT_SIZE + 2, BASE_FONT_HEIGHT * TEXT_SIZE + 2, mBackgroundColor);
        getTFT().setCursor(mXText, mYText);
        getTFT().print(mText);
    }
    
    
}
