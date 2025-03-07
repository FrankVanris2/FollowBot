/*
By: Frank Vanris
Date: 3/5/2025
Desc: Creating a GPS module that will be used in order to obtain the actual position of wheret the robot is.
*/

#pragma once
#define GPS_SIZE 2

enum GPSIndices {
    LAT = 0,
    LON
};

class GPS {

public:

    GPS();

    void gps_setup();
    void gps_loop();

    void setGPS(double lat, double lon) {
        gpsData[LAT] = lat;
        gpsData[LON] = lon;
    }

    double* getGPSData() { return gpsData;}

private:
    
    const uint32_t GPSBaud;
    double gpsData[GPS_SIZE];
};

extern GPS myGPS;