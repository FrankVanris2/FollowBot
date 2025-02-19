/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a Keyboard interface
*/

#pragma once
#include "FrameBase.h"
#include <unordered_map>

class TFT_eSPI;

enum KeyboardButtons {
    KBD_BACK_BUTTON,
    KBD_INPUT_BOX,
    KBD_NUMBER_1,
    KBD_NUMBER_2
};

class Keyboard : public FrameBase<KeyboardButtons>{
public:

    void setup(TFT_eSPI& tft);

    virtual void draw();

    virtual bool touchScreenEvent(int x, int y);
    

private:



};

extern Keyboard keyboard;