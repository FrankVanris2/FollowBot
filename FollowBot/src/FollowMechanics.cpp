/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/

#include "FollowMechanics.h"
#include "FollowBotClient.h"
#include "Arduino.h"


// Universal Object
FollowMechanics followMechanics;

// Constructor
FollowMechanics::FollowMechanics() {}


// Setup
void FollowMechanics::followMechanics_Setup() {

}

// Loop
void FollowMechanics::followMechanics_Loop() {
    long followRSSI = followBotClient.getRSSI();
    Serial.print("RSSI Value: ");
    Serial.println(followRSSI);
}
