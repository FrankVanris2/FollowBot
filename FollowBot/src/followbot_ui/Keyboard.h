/*
By: Frank Vanris
Date: 2/15/2025
Desc: Creating a Keyboard interface
*/

#pragma once
#include "UIComponent.h"
#include <unordered_map>

class TFT_eSPI;

class Keyboard : public UIComponent{

public:

    void setup();

    virtual void drawScreen();

    virtual bool touchScreenEvent(int x, int y);
    

private:



};