/*
By: Frank Vanris
Date: 2/11/2025
Desc: Creating a connection frame where it will show whether if you are connected or not
on the screen
*/

#pragma once
#include "FrameBase.h"

class TFT_eSPI;

class ConnectionFrame : public FrameBase {
public:
    ConnectionFrame();

    void setup(TFT_eSPI& tft);

    virtual void drawScreen();

    virtual void touchScreenEvent();
        
private:

};