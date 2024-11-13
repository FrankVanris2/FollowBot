/*
* By: Frank Vanris
* Date: 8/26/2024
* Desc: Creating an object avoidance script that will allow the robot to avoid obstacles.
* Will be updated throughout the different sensors that we apply to this robot
*/

#pragma once

class ObjectAvoidance {
public:

    ObjectAvoidance();

    void objectAvoidance_Setup();
    void objectAvoidance_Loop();

    //getting the distance;
    float getDistance1() const {
        return mDistance1;
    }

    float getDistance2() const {
        return mDistance2;
    }

private:
    unsigned long mPreviousMillis;
    float mDistance1, mDistance2;
    
    void checkDistance();

};

extern ObjectAvoidance objectAvoidance;