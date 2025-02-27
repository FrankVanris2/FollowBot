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
        
    private:
        //Interval
        unsigned long interval;
        unsigned long previousMillis;
        double gyroData[6];
};

extern Gyroscope gyroscope;