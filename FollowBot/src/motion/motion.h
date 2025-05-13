#pragma once
#include "Encoders.h"
#include "Gyroscope.h"
#include "Motors.h"

class Motion {
public:
    // singleton access
    static Motion& getInstance() {
        static Motion instance;
        return instance;
    }

    // delete copy constructor and assignment operator
    Motion(const Motion&) = delete;
    void operator=(const Motion&) = delete;

    // initialization with dependencies
    void initialize(Encoders& encoders, Gyroscope& gyro, Motors& motors) {
        mEncoders = &encoders;
        mGyro = &gyro;
        mMotors = &motors;
    }

    // motion interface
    void setVelocity(float linear, float angular);
    void update();

private:
    Motion() = default; // private constructor

    // dependency pointers
    Encoders* mEncoders = nullptr;
    Gyroscope* mGyro = nullptr;
    Motors* mMotors = nullptr;

    // motion state
    float m_targetLinear = 0;
    float m_targetAngular = 0;
    const float WHEEL_BASE = 0.28f; // meters
};

// Singleton instance declaration
extern Motion motion;