/*
* By: Frank Vanris
* Date: 8/26/2024
* Desc: Creating a Object Avoidance script in order to prevent the robot from colliding with unknown objects
*/

#include "ObjectAvoidance.h"
#include "Motors.h"
#include "MotorControlStates.h"
#include "Arduino.h"

//Sensor 1
const int TRIG_PIN1 = 9;
const int ECHO_PIN1 = 10;

//Sensor 2
const int TRIG_PIN2 = 11;
const int ECHO_PIN2 = 12;



//Distances:
float distance1, distance2;

// Setting state
MotorStates motorState = STOP;

// Universal Object
ObjectAvoidance objectAvoidance;

// Constructor
ObjectAvoidance::ObjectAvoidance(): duration1(0.0), duration2(0.0) {}


void ObjectAvoidance::objectAvoidance_Setup() {
    pinMode(TRIG_PIN1, OUTPUT);
    pinMode(ECHO_PIN1, INPUT);
    pinMode(TRIG_PIN2, OUTPUT);
    pinMode(ECHO_PIN2, INPUT);
}

void ObjectAvoidance::objectAvoidance_Loop() {
    // Sensor 1
    digitalWrite(TRIG_PIN1, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN1, LOW);
    duration1 = pulseIn(ECHO_PIN1, HIGH);
    distance1 = (duration1 * .0343) / 2;
    Serial.print("Distance1: ");
    Serial.println(distance1);

    // Sensor 2
    digitalWrite(TRIG_PIN2, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN2, LOW);
    duration2 = pulseIn(ECHO_PIN2, HIGH);
    distance2 = (duration2 * .0343) / 2;
    Serial.print("Distance2: ");
    Serial.println(distance2);

    //setting the distance
    setDistance1(distance1);
    setDistance2(distance2);
    
    delay(100);
}