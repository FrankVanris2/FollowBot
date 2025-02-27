/*
By: Frank Vanris
Date: 2/26/2025
Desc: Creating a Gyroscope that will give important information and Data which is essential for mapping.
*/

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

        double* getGyroData() { return gyroData;}
        
    private:
        //Interval
        unsigned long interval;
        unsigned long previousMillis;
        static const int DATA_SIZE = 6;
        double gyroData[DATA_SIZE];

        enum DataIndices {
            AX = 0,
            AY,
            AZ,
            GX,
            GY,
            GZ
        };
};

extern Gyroscope gyroscope;