/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: This will consist of all the main methods, and function that will 
* be needed to run our robot which will then be brought to the main
*/

#pragma once
#include <Arduino.h>

#include "states&types/Types.h"
#include "motors/Motors.h"
#include "gps/GPS.h"

class FollowBotManager {

public:

    FollowBotManager();

    void followBotSetup();
    
    void followBotLoop();
    
    //temperature getters and setters
    double getTemperature() const {
        return mOutputData.mTemperature;
    }

    void setTemperatureParams(double temp) {
        mIsDirty = true;
        mOutputData.mTemperature = temp;
    }

    //for clock
    void setClock(int day, int month, int year, int hour, int minute, int second) {

        //Format the date and time into a single string
        char clockBuffer[25];
        snprintf(clockBuffer, sizeof(clockBuffer), "%02d/%02d/%04d %02d:%02d:%02d", day, month, year, hour, minute, second);

        mIsDirty = true;
        mOutputData.mClock = String(clockBuffer);
    }

    void setGPSData(double lat, double lon) {
        mIsDirty = true;
        mOutputData.mCoordinates[LAT] = lat;
        mOutputData.mCoordinates[LON] = lon;
    }

    void setBotID() {
        mIsDirty = true;
        mOutputData.mBotID = 1234;
    }

    int getBotID() const { return mOutputData.mBotID; }

    double* getGPSData() {
        return mOutputData.mCoordinates;
    }


    String getClock() const { return mOutputData.mClock; }

    void setCurrentControl(const String& control) {
        if(control != mCurrentControl) {
            myMotors.setDirection(MOTOR_STOP);
            mCurrentControl = control;
        }   
    }

    const String& getCurrentControl() const {
        return mCurrentControl;
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
    String mCurrentControl;
};

extern FollowBotManager followBotManager;