#pragma once

#include "FrameBase.h"

class TFT_eSPI;

enum ManualControlScreenComponents {
    // Define components specific to ManualControlScreen here
};

class ManualControlScreen : public FrameBase<ManualControlScreenComponents> {
public:
    void setup(TFT_eSPI& tft) override;
    void draw() override;
    bool touchScreenEvent(int x, int y) override;
};

extern ManualControlScreen manualControlScreen;