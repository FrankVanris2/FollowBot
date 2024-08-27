/*
* By: Frank Vanris
* Date: 8/27/2024
* Desc: Creating a temperature reader to read the temperature within the robot
*/

#pragma once

class TemperatureReader {
public:

    TemperatureReader();

    void temperatureReader_Setup();
    void temperatureReader_Loop();

private:
};