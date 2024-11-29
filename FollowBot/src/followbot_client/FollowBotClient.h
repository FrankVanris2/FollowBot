/*
* By: Frank Vanris
* Date: 8/21/2024
* Desc: Creating a Robot client that will interface with the server which will pass information down to the website and the mobile app*/

#pragma once
#include "Arduino.h"
class FollowBotClient {
public:

    FollowBotClient();

    void followBotClient_Setup();
    void followBotClient_Loop();

    long getRSSI() {
        return mRSSI;
    }

private:

    void printWifiStatus();

    void postRobotInfo();
    void getMove();

    void checkServerConnection();
 
    unsigned long mPreviousMillisMove;

    int mCountMoves;
    int mConnectionStatus;
    long mRSSI;
    bool mServerConnected;
    String mIPAddress;
};

extern FollowBotClient followBotClient;