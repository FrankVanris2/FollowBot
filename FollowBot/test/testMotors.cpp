/*
By: Frank Vanris
Date: 11/5/2024
Desc: Tests the Motors.cpp
*/

#include "unity.h"
#include <string>
#include <iostream>


const uint16_t MED_SPEED = 200;


class MotorDirection {
public:
    MotorDirection() {
        mNewDirection = "STOP";
    }

    void setDirection(std::string dir) {
        if (dir == "FORWARD" || dir == "BACKWARD" || dir == "LEFT" || dir == "RIGHT" || dir == "STOP") {
            mNewDirection = dir;
        } else {
            mNewDirection = "STOP";
        }  
    }

    void switchToUserControl() {
        mNewDirection = "STOP";
    }

    std::string getDirection() {
        return mNewDirection;
    }

private:
    std::string mNewDirection;

};
class Adafruit_DCMotor {
public:
    void setSpeed(uint16_t speed) {
        this->speed = speed;
    }

    uint16_t getSpeed() {
        return speed;
    }

private:
    uint16_t speed;
};

class Adafruit_MotorShieldImpl {
public:
    Adafruit_MotorShieldImpl() {
        for (int i = 0; i < numMotors; ++i) {
            dcmotors[i] = new Adafruit_DCMotor();
        }
    }

    ~Adafruit_MotorShieldImpl() {
        for (int i = 0; i < numMotors; ++i) {
            delete dcmotors[i];
        }
    }
    Adafruit_DCMotor* getMotor(uint8_t num) {
        if (num < numMotors - 3 || num > numMotors) {
            return NULL;
        }
        return dcmotors[num - 1];
    }

private:
Adafruit_DCMotor* dcmotors[4];
int numMotors = 4;


};


Adafruit_MotorShieldImpl motorShieldImpl;
MotorDirection motorDirectionImpl;

Adafruit_DCMotor* motor1 = motorShieldImpl.getMotor(1);
Adafruit_DCMotor* motor2 = motorShieldImpl.getMotor(2);
Adafruit_DCMotor* motor3 = motorShieldImpl.getMotor(3);
Adafruit_DCMotor* motor4 = motorShieldImpl.getMotor(4);

void setUp(void) {
    // Set up code here (if needed)
    

    motor1->setSpeed(MED_SPEED);
    motor2->setSpeed(MED_SPEED);
    motor3->setSpeed(MED_SPEED);
    motor4->setSpeed(MED_SPEED);

}

void tearDown(void) {
    // Clean up code here (if needed)
}

void testMotors(void) {
    TEST_ASSERT_EQUAL(motorShieldImpl.getMotor(1)->getSpeed(), MED_SPEED);
    TEST_ASSERT_EQUAL(motorShieldImpl.getMotor(2)->getSpeed(), MED_SPEED);
    TEST_ASSERT_EQUAL(motorShieldImpl.getMotor(3)->getSpeed(), MED_SPEED);
    TEST_ASSERT_EQUAL(motorShieldImpl.getMotor(4)->getSpeed(), MED_SPEED);

    motor4->setSpeed(100);
    TEST_ASSERT_EQUAL(motorShieldImpl.getMotor(4)->getSpeed(), 100);
    
    
}

void testMotorDirectionChange(void) {
    TEST_ASSERT_EQUAL_STRING(motorDirectionImpl.getDirection().c_str(), "STOP");

    motorDirectionImpl.setDirection("FORWARD");
    TEST_ASSERT_EQUAL_STRING(motorDirectionImpl.getDirection().c_str(), "FORWARD");

    motorDirectionImpl.setDirection("BACKWARD");
    TEST_ASSERT_EQUAL_STRING(motorDirectionImpl.getDirection().c_str(), "BACKWARD");

    motorDirectionImpl.setDirection("LEFT");
    TEST_ASSERT_EQUAL_STRING(motorDirectionImpl.getDirection().c_str(), "LEFT");

    motorDirectionImpl.setDirection("RIGHT");
    TEST_ASSERT_EQUAL_STRING(motorDirectionImpl.getDirection().c_str(), "RIGHT");

    motorDirectionImpl.setDirection("STOP");
    TEST_ASSERT_EQUAL_STRING(motorDirectionImpl.getDirection().c_str(), "STOP");

    motorDirectionImpl.setDirection("INVALID");
    TEST_ASSERT_EQUAL_STRING(motorDirectionImpl.getDirection().c_str(), "STOP");

}

void testUserControl(void) {
    motorDirectionImpl.setDirection("FORWARD");
    
    motorDirectionImpl.switchToUserControl();
    TEST_ASSERT_EQUAL_STRING(motorDirectionImpl.getDirection().c_str(), "STOP");
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(testMotors);
    RUN_TEST(testMotorDirectionChange);
    RUN_TEST(testUserControl);
    return UNITY_END();
}
    