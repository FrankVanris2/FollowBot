/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: This will consist of all the main methods, and function that will 
* be needed to run our robot which will then be brought to the main
*/

#pragma once
#include <Arduino.h>

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

private:
    String mDirection; 
};

extern FollowBotManager followBotManager;