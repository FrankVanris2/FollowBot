/*
By: Frank Vanris
Date: 2/10/2025
Desc: Creating a text bounds where you can place the text on the button either in the middle left, or right
*/

#pragma once

#include <array>
#include "Adafruit_ST7796S_kbv.h"
class TextBounds {
public:

    TextBounds();

    enum TextAlighment {
        CENTER,
        LEFT,
        RIGHT
    };

    TextBounds(Adafruit_ST7796S_kbv& tftInstance);

    // Center the text
    std::array<int, 2> centerText(int x, int y, int width, int height);

    // Place the text on the left
    std::array<int, 2> leftText(int x, int y, int width, int height);

    //Place the text on the right
    std::array<int, 2> rightText(int x, int y, int width, int height);


private:
    Adafruit_ST7796S_kbv* tftRef;

};

extern TextBounds textBounds;