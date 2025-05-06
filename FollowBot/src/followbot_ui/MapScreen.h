#pragma once

#include "FrameBase.h"

class TFT_eSPI;

enum MapScreenComponents {
    // Define components specific to MapScreen here
};

class MapScreen : public FrameBase<MapScreenComponents> {
public:
    void setup(TFT_eSPI& tft) override;
    void draw() override;
    bool touchScreenEvent(int x, int y) override;
};

extern MapScreen mapScreen;