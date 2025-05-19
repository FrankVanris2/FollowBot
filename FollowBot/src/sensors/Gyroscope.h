/*
By: Frank Vanris
Date: 2/26/2025
Desc: Creating a Gyroscope that will give important information and Data which is essential for mapping.
*/

#pragma once
#define DATA_SIZE 6

enum DataIndices {
    AX = 0,
    AY,
    AZ,
    GX,
    GY,
    GZ
};

class Gyroscope {
    public:

        Gyroscope();
        void gyroscope_Setup();
        void gyroscope_Loop();

        void setGyroData(double ax, double ay, double az, double gx, double gy, double gz) {
            gyroData[AX] = ax;
            gyroData[AY] = ay;
            gyroData[AZ] = az;
            gyroData[GX] = gx;
            gyroData[GY] = gy;
            gyroData[GZ] = gz;
        }

        double* getGyroData() { return gyroData; }
        float getYaw() const { return m_currentYaw; }
        void resetYaw() { m_currentYaw = 0; }
        
    private:
        // interval to send to pi
        unsigned long interval;
        unsigned long previousMillis;   
        double gyroData[DATA_SIZE];

        float m_currentYaw = 0;
};

extern Gyroscope gyroscope;