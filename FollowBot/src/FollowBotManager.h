/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: This will consist of all the main methods, and function that will 
* be needed to run our robot which will then be brought to the main
*/

#pragma once
#include <Arduino.h>
#include "Types.h"

class FollowBotManager {

public:

    FollowBotManager();

    void followBotSetup();
    void followBotLoop();

    const String& getDirection() const {
        return mDirection;
    }

    void setDirection(const String& direction) {
        mDirection = direction;
    } 

    //temperature getters and setters
    float getTemperature() const {
        return mOutputData.mTemperature;
    }

    void setTemperature(float temp) {
        mOutputData.mTemperature = temp;
    }

    //heat index getters and setters
    float getHeatIndex() const {
        return mOutputData.mHeatIndex;
    }

    void setHeatIndex(float heatIndex) {
        mOutputData.mHeatIndex = heatIndex;
    }

    const OutputData& getOutputData() const {
        return mOutputData;
    }

private:
    String mDirection; 
    OutputData mOutputData;

};

extern FollowBotManager followBotManager;