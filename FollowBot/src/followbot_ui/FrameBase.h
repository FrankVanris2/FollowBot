/*
By: Frank Vanris
Date: 2/11/2025
Desc: Creating an abstract class for drawing the screen
*/

#pragma once

//Abstract Base class for all frames
class TFT_eSPI;

class FrameBase {
public:

    // Pure virtual function
    virtual void drawScreen() = 0;

    virtual void touchScreenEvent(int x, int y) = 0;

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