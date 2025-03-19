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
const int TENTH_SECOND = 100; // ms


// Universal Object
FollowMechanics followMechanics;

// Constructor
FollowMechanics::FollowMechanics():  mRSSIAvg(0), mRSSITotal(0), previousMillis(0) {}


// Setup
void FollowMechanics::followMechanics_Setup() {

}

// Loop
void FollowMechanics::followMechanics_Loop() {
    if ((unsigned long) (millis() - previousMillis) >= TENTH_SECOND) {
        previousMillis = millis();

        
        
        Serial.println(String("Bluetooth is enabled: ") + followBotBluetooth.isEnabled());
        if (followBotBluetooth.isEnabled()) {
            followMechanics_Averaging(); // Get and average RSSI
            Serial.println(String("FollowMechanics_Loop(), RSSI Value: ") + mRSSIAvg);
            //if (mRSSIAvg < -50) {
                //driveTo_Test_1();
                driveTo_Test_2();
            //} else {
             //   myMotors.stopMoving();
            //}
            
            //driveTo_Test_2();
        }
    }
}

void FollowMechanics::followMechanics_Averaging() {
    int followRSSI = followBotBluetooth.getRSSI();
    rssiList.push_front(followRSSI);
    mRSSITotal += followRSSI;

    if (rssiList.size() > 50) {
        mRSSITotal -= rssiList.back();
        rssiList.pop_back();
    }
    mRSSIAvg = mRSSITotal / (int) rssiList.size();


    Serial.print("FollowMechanics, RSSI Avg Value: ");
    Serial.println(mRSSIAvg);
}

void FollowMechanics::driveTo_Test_1() {
    struct GeoLoc currentMobileLoc = followBotBluetooth.getMobileGPSData();
    struct GeoLoc currentRobotLoc = myGPS.getRobotGPSData();
    Serial.println(String("driveTo_Test_1(), Current Robot Location: ") + currentRobotLoc.lat + ", " + currentRobotLoc.lon);
    Serial.println(String("driveTo_Test_1(), Current Mobile Location: ") + currentMobileLoc.lat + ", " + currentMobileLoc.lon);
    if(currentRobotLoc.lat != 0 && currentRobotLoc.lon != 0) {
        float d = geoDistance(currentRobotLoc, currentMobileLoc);
        float t = geoBearing(currentRobotLoc, currentMobileLoc) - compass.geoHeading();

        Serial.println(String("driveTo_Test_1(), Distance: ") + d);
        Serial.println(String("driveTo_Test_1(), Bearing: ") + geoBearing(currentRobotLoc, currentMobileLoc));
        Serial.println(String("driveTo_Test_1(), Heading: ") + compass.geoHeading());
        Serial.println(String("driveTo_Test_1(), Turn: ") + t);

        if (d >= 3.0) {
          drive(d, t);
        } else {
          myMotors.stopMoving();
        }
    }
}

void FollowMechanics::driveTo_Test_2() {
    struct GeoLoc currentMobileLoc = followBotBluetooth.getMobileGPSData();
    struct GeoLoc currentRobotLoc = myGPS.getRobotGPSData();
    Serial.println(String("driveTo_Test_2(), Current Robot Location: ") + currentRobotLoc.lat + ", " + currentRobotLoc.lon);
    Serial.println(String("driveTo_Test_2(), Current Mobile Location: ") + currentMobileLoc.lat + ", " + currentMobileLoc.lon);
    if (currentRobotLoc.lat != 0 && currentRobotLoc.lon != 0) {
        float dist = geoDistance(currentRobotLoc, currentMobileLoc);
        float latLongBearing = geoBearing(currentRobotLoc, currentMobileLoc);
        float compassHeading = compass.geoHeading();    
        float turn = compassHeading - latLongBearing;
        if (turn < -180) {
            turn += 360;
        } else if (turn > 180) {
            turn -= 360;
        }

        Serial.println();
        Serial.println(String("driveTo_Test_2(), Distance: ") + dist);
        Serial.println(String("driveTo_Test_2(), latLongBearing: ") + latLongBearing + ", Compass Heading: " + compassHeading + ", Turn: " + turn);

        if(dist >= 3.0) {
            myMotors.turn(turn);
        } else {
          myMotors.justStop();
        }
    }
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
    Serial.println(String("drive(), Turn: ") + t + " Original: " + turn);

    float t_modifier = (180.0 - abs(t)) / 180.0;
    float autoSteerA = 1;
    float autoSteerB = 1;

    if (t < 0) {
        autoSteerB = t_modifier;
    } else if (t > 0) {
        autoSteerA = t_modifier;
    }

    Serial.println(String("drive(), SteerA: ") + autoSteerA);
    Serial.println(String("drive(), SteerB: ") + autoSteerB);

    //Adapt for 4 motors (Example: differential drive);
    int speedA = (int) (((float) autoThrottle) * autoSteerA);
    int speedB = (int) (((float) autoThrottle) * autoSteerB);


    int leftSpeed = speedA;
    int rightSpeed = speedB;
    myMotors.setMotorSpeed(leftSpeed, rightSpeed);
}

float FollowMechanics::geoDistance(struct GeoLoc &a, struct GeoLoc &b) {
    const float R = 6371000; // m
    float p1 = a.lat * DEGTORAD;
    float p2 = b.lat * DEGTORAD;
    float dp = (b.lat-a.lat) * DEGTORAD;
    float dl = (b.lon-a.lon) * DEGTORAD;
  
    float x = sin(dp/2) * sin(dp/2) + cos(p1) * cos(p2) * sin(dl/2) * sin(dl/2);
    float y = 2 * atan2(sqrt(x), sqrt(1-x));

    Serial.println(String("geoDistance(), Distance between you and the robot: ") + (R * y) + "m");
  
    return R * y;
}

float FollowMechanics::geoBearing(struct GeoLoc &a, struct GeoLoc &b) {
    float y = sin(b.lon-a.lon) * cos(b.lat);
    float x = cos(a.lat)*sin(b.lat) - sin(a.lat)*cos(b.lat)*cos(b.lon-a.lon);
    return atan2(y, x) * RADTODEG;
}




