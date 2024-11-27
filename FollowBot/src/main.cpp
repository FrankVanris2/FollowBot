#include <Arduino.h>
#include "followbot_manager/FollowBotManager.h"


/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: main will consist of the main loop and setup
*/

//testing purposes (Currently)
void setup() {
  Serial.begin(9600);
  followBotManager.followBotSetup();
}

//testing purposes (Currently)
void loop() {
  followBotManager.followBotLoop();
}
