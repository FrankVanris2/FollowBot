/*
* By: Frank Vanris
* Date: 8/21/2024
* Desc: Creating a Robot client that will interface with the server which will pass information down to the website and the mobile app*/

#pragma once
#include <Arduino.h>

class FollowBotClient {
public:
    FollowBotClient();

    void followBotClient_Setup();
    void followBotClient_Loop();

    long getRSSI() {
        return mRSSI;
    }

    void checkRSSI();

    bool isConnected() {
        return mIsConnected;
    }
    
private:
    void printWifiStatus();
    bool postRobotInfo();
    bool getMove();

    

    
 
    unsigned long mPreviousMillisMove;
    unsigned long lastServerCheck;

    bool mIsConnected;
    int mCountMoves;
    int mWifiConnectionStatus;
    int mServerNotConnected;
    long mRSSI;
    String mIPAddress;
};

extern FollowBotClient followBotClient;