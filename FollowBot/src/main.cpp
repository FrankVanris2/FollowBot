#include <Arduino.h>
#include "FollowBotManager.h"


/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: main will consist of the main loop and setup
*/

//testing purposes (Currently)
void setup() {
  Serial.begin(9600);
  followBotManager.followBotSetup();
  // put your setup code here, to run once:
}

//testing purposes (Currently)
void loop() {
  followBotManager.followBotLoop();
  
  // put your main code here, to run repeatedly:
}
