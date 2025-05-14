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
    String getActionData();
    void handleActionData(String dataString);

    unsigned long mPreviousMillisMove;
    unsigned long lastServerCheck;

    // Connection state
    bool mIsConnected;              // WiFi connection state
    int mCountMoves;                // Count of movement commands
    int mWifiConnectionStatus;      // WiFi status code
    int mServerNotConnectedCnt;     // Failed connection counter
    long mRSSI;                     // Signal Strength in dBm
    String mIPAddress;              // Server IP address
};

// Global singleton instance
extern FollowBotClient followBotClient;