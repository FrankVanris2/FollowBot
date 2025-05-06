#pragma once

#include "FrameBase.h"

class TFT_eSPI;

enum IdleScreenComponents {
    // Define components specific to IdleScreen here
};

class IdleScreen : public FrameBase<IdleScreenComponents> {
public:
    void setup(TFT_eSPI& tft) override;
    void draw() override;
    bool touchScreenEvent(int x, int y) override;
};

extern IdleScreen idleScreen;