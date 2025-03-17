/*
By: Frank Vanris
Date: 3/16/2025
Desc: Creating a bluetooth connection for my arduino uno rev4 board.
*/

#pragma once

class FollowBotBluetooth {

public:
    FollowBotBluetooth();
    void setup();
    void loop();

private:
    bool isError;
};

extern FollowBotBluetooth followBotBluetooth; // Declare the singleton instance