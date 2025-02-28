/*
By: Frank Vanris
Date: 9/19/2024
Desc: Creating follow mechanics between the user and the robot
*/

#include <list>

#include "FollowMechanics.h"
#include "followbot_client/FollowBotClient.h"
#include "objectavoidance&detection/ObjectDetection.h"
#include "states&types/MotorControlStates.h"
#include "motors/Motors.h"



// Interval
const int TENTH_SECOND = 100;

// Distance values
const int FOLLOW_DISTANCE = 130; // Ideal distance to maintain from user
const int CLOSE_DISTANCE = 100; // Too close-stop
const int ALIGN_TOLERANCE = 20; // Small difference in left/right distances


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

        //followBotClient.checkRSSI();
        //followMechanics.followMechanics_Averaging();

        myMotors.motorLoop();
        followMechanics_Algorithm();
    }
}


void FollowMechanics::followMechanics_Averaging() {
    //Add rssi value to list
        long followRSSI = followBotClient.getRSSI();
        rssiList.push_front(followRSSI);
        mRSSITotal += followRSSI;

        //if list is > 30 remove the last value 
        if (rssiList.size() > 30) {
            mRSSITotal -= rssiList.back();
            rssiList.pop_back();
        }
        mRSSIAvg = mRSSITotal / (long) rssiList.size();


        //Serial.print("FollowMechanics, RSSI Avg Value: ");
        //Serial.println(mRSSIAvg);
}

void FollowMechanics::followMechanics_Algorithm() {
    int distance1 = objectDetection.getDistance1();
    int distance2 = objectDetection.getDistance2();
    int distance3 = objectDetection.getDistance3();

    Serial.println(String("Distance 1: ") + distance1 + ", Distance 2: " + distance2 + ", Distance 3: " + distance3);

    if (distance2 < CLOSE_DISTANCE) {
        // **1. If user is too close, STOP**
        Serial.println("Stopping - Too close to user");
        myMotors.setDirection(MOTOR_STOP);

    } else if(distance2 > FOLLOW_DISTANCE) {
        // **2. If user is far, MOVE FORWARD**
        Serial.println("Following User (Going Forward)");
        myMotors.setDirection(MOTOR_FORWARD);

    }else if(distance1 < distance3 - ALIGN_TOLERANCE) {
        // **3. If user is more to the left, turn left**
        Serial.println("User is on the Left, Turning Left");
        myMotors.setDirection(MOTOR_LEFT);

    } else if(distance3 < distance1 - ALIGN_TOLERANCE) {
        // **4. If user is more to the left, turn LEFT**
        
        Serial.println("User is on the Right, Turning Right");
        myMotors.setDirection(MOTOR_RIGHT);
    } else {
        // **5. If distances are balanced, keep moving forward**
        Serial.println("User is aligned, Going Forward");
        myMotors.setDirection(MOTOR_FORWARD);
    }
    
 
}


