/*
* By: Frank Vanris
* Date: 8/26/2024
* Desc: Creating a Object Avoidance script in order to prevent the robot from colliding with unknown objects
*/

#include "ObjectAvoidance.h"
#include "Arduino.h"

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;


// Universal Object
ObjectAvoidance objectAvoidance;

// Constructor
ObjectAvoidance::ObjectAvoidance(): duration(0.0), distance(0.0) {}


void ObjectAvoidance::objectAvoidance_Setup() {
    pinMode(TRIG_PIN, OUTPUT);

    pinMode(ECHO_PIN, INPUT);
}

void ObjectAvoidance::objectAvoidance_Loop() {
    digitalWrite(TRIG_PIN, LOW);

    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);

    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);

    distance = (duration * .0343) / 2;

    Serial.print("Distance: ");

    Serial.println(distance);

    delay(100);
}