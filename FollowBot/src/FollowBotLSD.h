/*
By: Frank Vanris
Date: 9/19/2024
Desc: Using an LSD screen to allow the user to input their ssid and pass for the robot in order for it to connect to the server
*/

#pragma once

class LSDScreen {
public:

    LSDScreen();

    void myLSDScreen_Setup();

    void myLSDScreen_Loop();

private:
};

extern LSDScreen myLSDScreen;