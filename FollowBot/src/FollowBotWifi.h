/*
* By: Frank Vanris
* Date: 8/20/2024
* Desc: Wifi access to the Arduino is needed for uploading sketches wirelessly
*/

#pragma once

class FollowBotWifi {
public:

    FollowBotWifi();

    void followBotWifi_Setup();

    void followBotWifi_Loop();

    void printWiFiStatus();

private:
    const char* ssid;
    const char* password;
    int keyIndex;
    int status;

};

extern FollowBotWifi followBotWifi;