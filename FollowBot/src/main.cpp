#include <Arduino.h>
#include "FollowBotManager.h"

/*
* By: Frank Vanris
* Date: 8/8/2024
* Desc: main will consist of the main loop and setup
*/

//testing purposes (Currently)
void setup() {
  followBotManager.followBotSetup();
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:
}

//testing purposes (Currently)
void loop() {
  followBotManager.followBotLoop();
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
  // put your main code here, to run repeatedly:
}
