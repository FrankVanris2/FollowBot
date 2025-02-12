/*
By: Frank Vanris
Date: 2/11/2025
Desc: The main frame where everything is projected with options
*/

#pragma once

#include "FrameBase.h"


class TFT_eSPI;
class Button;

class MainFrame : public FrameBase {

public:
    
    void setup(TFT_eSPI&  tft);


    void drawScreen();

    void touchScreenEvent(int x, int y);

private:

    Button *btnSSID;
    Button *btnPassword;
    Button *btnConnect;
};

extern MainFrame mainFrame;