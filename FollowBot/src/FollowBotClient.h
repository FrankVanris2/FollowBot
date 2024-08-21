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

    void read_response();

    void printWifiStatus();
    
    int keyIndex;
    int status;
};

extern FollowBotClient followBotClient;