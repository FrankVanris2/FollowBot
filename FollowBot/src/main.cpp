#include "Arduino.h"
#include "followbot_manager/FollowBotManager.h"

void setup() {
  Serial.begin(9600);
  // Wait for serial port to connect. Needed for native USB
  while (!Serial) {
    ; 
  }
  followBotManager.followBotSetup();
}

void loop() {
  followBotManager.followBotLoop();
}


