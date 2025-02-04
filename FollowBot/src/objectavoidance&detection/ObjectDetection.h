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
    float getDistance1() const {
        return mDistance1;
    }

    float getDistance2() const {
        return mDistance2;
    }

    float getDistance3() const {
        return mDistance3;
    }

    void setDistance1(float distance1) {
        mDistance1 = distance1;
    }

    void setDistance2(float distance2) {
        mDistance2 = distance2;
    }

    void setDistance3(float distance3) {
        mDistance3 = distance3;
    }

private:
    unsigned long mPreviousMillis;
    float mDistance1, mDistance2, mDistance3;
    
    void checkDistance();
};

extern ObjectDetection objectDetection;