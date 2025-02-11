/*
By: Frank Vanris
Date: 02/10/2025
Desc: Creating TextBounds
*/


#include "TextBounds.h"

TextBounds textBounds;

//Constructors

TextBounds::TextBounds() : tftRef(nullptr) {}

TextBounds::TextBounds(Adafruit_ST7796S_kbv &tftInstances) : tftRef(&tftInstances) {}

std::array<int, 2> TextBounds::centerText(int x, int y, int width, int height) {
    int16_t x1, y1;
    uint16_t w, h;
    tftRef->getTextBounds("SSID", 0, 0, &x1, &y1, &w, &h);
    return std::array<int, 2>({x + (width - w) / 2, y + (height - h) / 2});
}