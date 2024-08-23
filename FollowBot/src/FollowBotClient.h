/*
* By: Frank Vanris
* Date: 8/21/2024
* Desc: Creating a Robot client that will interface with the server which will pass information down to the website and the mobile app*/

#pragma once

class FollowBotClient {
public:

    FollowBotClient();

    void followBotClient_Setup();

    void followBotClient_Loop();

    

private:

    void printWifiStatus();

    //Testing purposes
    void test_read_response();

    void test_read_robotMovement();

    void testGet();

    void testGetMove();
    
    int keyIndex;
    int status;
    unsigned long interval;
    unsigned long previousMillis;
};

extern FollowBotClient followBotClient;