/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/


#include <list>
#include <Wire.h>
#include <math.h>

#include "sensors/Compass.h"
#include "FollowMechanics.h"
#include "followbot_client/FollowBotClient.h"

#include "states&types/MotorControlStates.h"
#include "states&types/FollowBotNavigation.h"
#include "states&types/MathematicalDefinitions.h"

#include "followbot_client/FollowBotBluetooth.h"
#include "motors/Motors.h"
#include "gps/GPS.h"

//#include "objectavoidance&detection/ObjectDetection.h"

// Interval
const int TENTH_SECOND = 100;


// Universal Object
FollowMechanics followMechanics;

// Constructor
FollowMechanics::FollowMechanics():  mRSSIAvg(0), mRSSITotal(0), previousMillis(0), enabled(false) {}


// Setup
void FollowMechanics::followMechanics_Setup() {

}

void FollowMechanics::drive(float distance, float turn) {
    int fullSpeed = 230;
    int stopSpeed = 0;
    int s = fullSpeed;
    if (distance < 8) {
        int wouldBeSpeed = s - stopSpeed;
        wouldBeSpeed *= distance / 8.0f;
        s = stopSpeed + wouldBeSpeed;
    }

    int autoThrottle = constrain(s, stopSpeed, fullSpeed);
    autoThrottle = 230;

    float t = turn;
    while (t < -180) t += 360;
    while (t > 180) t -= 360;
    Serial.print(String("Turn: ") + t + "Original: " + turn);

    float t_modifier = (180.0 - abs(t)) / 180.0;
    float autoSteerA = 1;
    float autoSteerB = 1;

    if (t < 0) {
        autoSteerB = t_modifier;
    } else if (t > 0) {
        autoSteerA = t_modifier;
    }

    Serial.println(String("SteerA: ") + autoSteerA);
    Serial.println(String("SteerB: ") + autoSteerB);

    //Adapt for 4 motors (Example: differential drive);
    int speedA = (int) (((float) autoThrottle) * autoSteerA);
    int speedB = (int) (((float) autoThrottle) * autoSteerB);

    int leftSpeed = speedA;
    int rightSpeed = speedB;
    myMotors.setMotorSpeed(leftSpeed, rightSpeed);
}

void FollowMechanics::driveTo(struct GeoLoc &loc, int timeout) {
    struct GeoLoc currentRobotLoc = myGPS.getRobotGPSData();
    if(currentRobotLoc.lat != 0 && currentRobotLoc.lon != 0 && enabled) {
        float d = 0;
        do {
            currentRobotLoc = myGPS.getRobotGPSData();
            d = geoDistance(currentRobotLoc, loc);
            float t = geoBearing(currentRobotLoc, loc) - compass.geoHeading();

            Serial.println(String("Distance: ") + geoDistance(currentRobotLoc, loc));
            Serial.println(String("Bearing: ") + geoBearing(currentRobotLoc, loc));
            Serial.println(String("Heading: ") + compass.geoHeading());

            drive(d, t);
            timeout -= 1;
        } while (d > 3.0 && enabled && timeout > 0);

        myMotors.motorStop();
    }
}

float FollowMechanics::geoDistance(struct GeoLoc &a, struct GeoLoc &b) {
    const float R = 6371000; // km
    float p1 = a.lat * DEGTORAD;
    float p2 = b.lat * DEGTORAD;
    float dp = (b.lat-a.lat) * DEGTORAD;
    float dl = (b.lon-a.lon) * DEGTORAD;
  
    float x = sin(dp/2) * sin(dp/2) + cos(p1) * cos(p2) * sin(dl/2) * sin(dl/2);
    float y = 2 * atan2(sqrt(x), sqrt(1-x));
  
    return R * y;
}

float FollowMechanics::geoBearing(struct GeoLoc &a, struct GeoLoc &b) {
    float y = sin(b.lon-a.lon) * cos(b.lat);
    float x = cos(a.lat)*sin(b.lat) - sin(a.lat)*cos(b.lat)*cos(b.lon-a.lon);
    return atan2(y, x) * RADTODEG;
}



// Loop 
void FollowMechanics::followMechanics_Loop() { 
    if ((unsigned long) (millis() - previousMillis) >= TENTH_SECOND) {
        previousMillis = millis();

        //followMechanics_Averaging(); // Get and average RSSI
        followMechanics_Algorithm(); // Through GPS and the compass.
        //myMotors.motorLoop();
        
    }
}


void FollowMechanics::followMechanics_Averaging() { 
    long followRSSI = followBotClient.getRSSI();
    rssiList.push_front(followRSSI);
    mRSSITotal += followRSSI;

    if (rssiList.size() > 10) {
        mRSSITotal -= rssiList.back();
        rssiList.pop_back();
    }
    mRSSIAvg = mRSSITotal / (long) rssiList.size();
    
    
    Serial.print("FollowMechanics, RSSI Avg Value: ");
    Serial.println(mRSSIAvg);      
}

void FollowMechanics::followMechanics_Algorithm() {
    struct GeoLoc currentMobileLoc = followBotBluetooth.getMobileGPSData();
    if (enabled) {
        driveTo(currentMobileLoc, GPS_FOLLOW_TIMEOUT);
    }
}


