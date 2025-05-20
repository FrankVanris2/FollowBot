 /*
* By: Frank Vanris
* Date: 12/05/2024
* Desc: Creating a setup for object detection in order to get the basic following mechanics down
*/

#include <Arduino.h>

#include "ObjectDetection.h"


//Universal Object
ObjectDetection objectDetection;

//delays
const int TENTH_SECOND = 100;


// Ultrasonice Snesor
const int TRIG_PIN1 = A2;
const int ECHO_PIN1 = A3;


//Constructor
ObjectDetection::ObjectDetection(): mDistance(0.0), mPreviousMillis(0) {}

void ObjectDetection::objectDetection_Setup() {
    Serial.println("Object Detection Setup");
    //Sensor Front
    pinMode(TRIG_PIN1, OUTPUT);
    pinMode(ECHO_PIN1, INPUT);
}

void ObjectDetection::objectDetection_Loop() {
    unsigned long currentMillis = millis();
    
    if((unsigned long) (currentMillis - mPreviousMillis) >= TENTH_SECOND) {
        mPreviousMillis = currentMillis;         
        checkDistance();
    }  
    
    
}

void ObjectDetection::checkDistance() {
    // Sensor Front
    digitalWrite(TRIG_PIN1, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN1, LOW);
    float duration1 = pulseIn(ECHO_PIN1, HIGH);
    setDistance((duration1 * .0343) / 2);
}


