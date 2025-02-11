
/*
By: Frank Vanris
Date: 02/10/2025
Desc: Creating a button class
*/
#pragma once

#include "Adafruit_ST7796S_kbv.h"

class Button {
public:

    Button();

    Button(Adafruit_ST7796S_kbv& tftInstance);
    
    void drawButton(int x, int y, int width, int height, const char* label);
    
    bool clickSpace(int x, int y, int width, int height);
    
private:
    Adafruit_ST7796S_kbv* tftRef;
};

extern Button button;