/*
* By: Frank Vanris
* Date: 12/5/2024
* Desc: Adding Sensors to obtain distance information between different objects*/

#pragma once

class ObjectDetection {
public:
    ObjectDetection();

    void objectDetection_Setup();
    void objectDetection_Loop();

    //getting the distance;
    float getDistance() const { return mDistance; }

    void setDistance(float distance) { mDistance = distance; }

private:
    unsigned long mPreviousMillis;
    float mDistance;
    
    void checkDistance();
};

extern ObjectDetection objectDetection;