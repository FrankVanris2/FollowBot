/* 
By: Frank Vanris
Date: 3/17/2025
Desc: Using the Compass hardware component for my robotic device to follow me
*/

#pragma once

class Compass {
public:
    Compass();

    void compass_Setup();
    void compass_loop();
    void displayCompassDetails(void);
    float geoHeading();

private:
    bool isError;
};

extern Compass compass;