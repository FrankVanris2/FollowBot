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

private:
    float duration1, distance1, duration2, distance2;

};

extern ObjectAvoidance objectAvoidance;