/*
By: Joseph 
Date: 5/12/2025
Desc: Creating a mapping frame
*/

#pragma once 

#include <unordered_map>
#include "FrameBase.h"

class TFT_eSPI;

enum MappingFrameComponents {
    MAPPING_TEXT,
    MAPPING_TEXT_WAIT,
    TO_MAIN_SCREEN_MAPPING,
    FOLLOWING_TEXT_COORD
};

class MappingFrame : public FrameBase<MappingFrameComponents> {
public:
    virtual void setup(TFT_eSPI& tft);
    virtual void draw();
    virtual bool touchScreenEvent(int x, int y);
    void updateCoordinatesStatus();
    void loop() override; // Overriding the base class method.

private:
    String mLastCoordStatus = "LAT: --- LNG: ---";
    unsigned long mLastCoordinatesCheckTime = 0;
    const unsigned long COORDINATES_CHECK_INTERVAL = 1000; // 1 second
};

extern MappingFrame mappingFrame;