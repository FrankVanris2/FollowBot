/*
By: Frank Vanris
Date: 2/11/2025
Desc: Creating an abstract class for drawing the screen
*/

#pragma once
#include <Arduino.h>

//Abstract Base class for all frames
class TFT_eSPI;

class UIComponent {
public:

    // Pure virtual function
    virtual void draw() = 0;

    virtual bool touchScreenEvent(int x, int y) {
        return false;
    } 

protected:
    TFT_eSPI&  getTFT() const { 
        return *tft;
    }

    void setTFT(TFT_eSPI& tft) {
        this->tft = &tft;
    }

private:
    TFT_eSPI* tft;
};