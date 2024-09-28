/*
* By: Frank Vanris
* Date: 8/26/2024
* Desc: Creating a Object Avoidance script in order to prevent the robot from colliding with unknown objects
*/

#include "ObjectAvoidance.h"
#include "Motors.h"
#include "MotorControlStates.h"
#include "Arduino.h"

//delays
const int TENTH_SECOND = 100;

//Sensor 1
const int TRIG_PIN1 = 9;
const int ECHO_PIN1 = 10;

//Sensor 2
const int TRIG_PIN2 = 11;
const int ECHO_PIN2 = 12;

// Setting state
MotorStates motorState = STOP;

// Universal Object
ObjectAvoidance objectAvoidance;

// Constructor
ObjectAvoidance::ObjectAvoidance(): mPreviousMillis(0) {}


void ObjectAvoidance::objectAvoidance_Setup() {
    Serial.println("Object Avoidance Setup");
    pinMode(TRIG_PIN1, OUTPUT);
    pinMode(ECHO_PIN1, INPUT);
    pinMode(TRIG_PIN2, OUTPUT);
    pinMode(ECHO_PIN2, INPUT);
}

void ObjectAvoidance::objectAvoidance_Loop() {
    unsigned long currentMillis = millis();
    
    if((unsigned long) (currentMillis - mPreviousMillis) >= TENTH_SECOND) {
        mPreviousMillis = currentMillis;         
        checkDistance();
    }  
    
    
}

void ObjectAvoidance::checkDistance() {
    // Sensor 1
    digitalWrite(TRIG_PIN1, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN1, LOW);
    float duration1 = pulseIn(ECHO_PIN1, HIGH);
    mDistance1 = (duration1 * .0343) / 2;
    //Serial.print("Distance1: ");
    //Serial.println(mDistance1);

    // Sensor 2
    digitalWrite(TRIG_PIN2, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN2, LOW);
    float duration2 = pulseIn(ECHO_PIN2, HIGH);
    mDistance2 = (duration2 * .0343) / 2;
    //Serial.print("Distance2: ");
    //Serial.println(mDistance2);

}