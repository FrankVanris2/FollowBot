/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: This will consist of all the main methods, and function that will 
* be needed to run our robot which will then be brought to the main
*/

#pragma once
#include <Arduino.h>
#include "states&types/Types.h"

class FollowBotManager {

public:

    FollowBotManager();

    void followBotSetup();
    
    void followBotLoop();
    
    //temperature getters and setters
    float getTemperature() const {
        return mOutputData.mTemperature;
    }

    void setTemperatureParams(float temp, float heatIndex) {
        Serial.println("FollowBotManager.setTemperatureParams()");
        mIsDirty = true;
        mOutputData.mTemperature = temp;
        mOutputData.mHeatIndex = heatIndex;
    }

    //heat index getters and setters
    float getHeatIndex() const {
        return mOutputData.mHeatIndex;
    }

    const OutputData& getOutputData() const {
        mIsDirty = false;
        return mOutputData;
    }

    bool getDirtyFlag() const {
        return mIsDirty;
    }
    
private:
    //String mDirection; 
    OutputData mOutputData;
    mutable bool mIsDirty;
};

extern FollowBotManager followBotManager;