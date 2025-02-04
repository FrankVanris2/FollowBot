 /*
* By: Frank Vanris
* Date: 12/05/2024
* Desc: Creating a setup for object detection in order to get the basic following mechanics down
*/

#include "ObjectDetection.h"
#include "Arduino.h"

//Universal Object
ObjectDetection objectDetection;

//delays
const int TENTH_SECOND = 100;

//Sensor 1
const int TRIG_PIN1 = 9;
const int ECHO_PIN1 = 10;

//Sensor 2
const int TRIG_PIN2 = 11;
const int ECHO_PIN2 = 12;

//Sensor 3
const int TRIG_PIN3 = 8;
const int ECHO_PIN3 = 7;


//Constructor
ObjectDetection::ObjectDetection(): mDistance1(0.0), mDistance2(0.0), mDistance3(0.0), mPreviousMillis(0) {}

void ObjectDetection::objectDetection_Setup() {
    Serial.println("Object Detection Setup");
    //Sensor Left
    pinMode(TRIG_PIN1, OUTPUT);
    pinMode(ECHO_PIN1, INPUT);

    //Sensor Middle
    pinMode(TRIG_PIN2, OUTPUT);
    pinMode(ECHO_PIN2, INPUT);

    //Sensor Right
    pinMode(TRIG_PIN3, OUTPUT);
    pinMode(ECHO_PIN3, INPUT);
}

void ObjectDetection::objectDetection_Loop() {
    unsigned long currentMillis = millis();
    
    if((unsigned long) (currentMillis - mPreviousMillis) >= TENTH_SECOND) {
        mPreviousMillis = currentMillis;         
        checkDistance();
    }  
    
    
}

void ObjectDetection::checkDistance() {
    // Sensor Left
    digitalWrite(TRIG_PIN1, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN1, LOW);
    float duration1 = pulseIn(ECHO_PIN1, HIGH);
    setDistance1((duration1 * .0343) / 2);


    // Sensor Middle
    digitalWrite(TRIG_PIN2, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN2, LOW);
    float duration2 = pulseIn(ECHO_PIN2, HIGH);
    setDistance2((duration2 * .0343) / 2);

    // Sensor Right
    digitalWrite(TRIG_PIN3, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN3, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN3, LOW);
    float duration3 = pulseIn(ECHO_PIN3, HIGH);
    setDistance3((duration3 * .0343) / 2);
}


