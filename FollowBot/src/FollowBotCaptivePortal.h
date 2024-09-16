/*
By: Frank Vanris
Date: 9/16/2024
Desc: Creating a Captive portal in order to put your user credentials into the device
in order to connect to the robot with any network
*/

#pragma once
#include "WiFiS3.h"
class CaptivePortal {
public:

    CaptivePortal();
    
    void captivePortal_Setup();
    void captivePortal_Loop();

    

private:
    void handleCaptivePortal(WiFiClient client);
};

extern CaptivePortal captivePortal;