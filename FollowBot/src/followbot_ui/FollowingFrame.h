/*
By: Frank Vanris
Date: 5/9/2025
Desc: Creating a following frame for when the robot is set to following mode
*/

#pragma once

#include <unordered_map>
#include "FrameBase.h"

class TFT_eSPI;

enum FollowingFrameComponents {
    FOLLOWING_TEXT,
    FOLLOWING_TEXT_WAIT,
    TO_MAIN_SCREEN
};

class FollowingFrame : public FrameBase<FollowingFrameComponents> {
public:
    virtual void setup(TFT_eSPI& tft);
    virtual void draw();
    virtual bool touchScreenEvent(int x, int y);
    void loop() override; // Overriding the base class method.
};

extern FollowingFrame followingFrame;