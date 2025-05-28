#pragma once
#include "sensors/Encoders.h"
#include "sensors/Gyroscope.h"
#include "motors/Motors.h"

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
    void motion_loop();
    void waitUntilTurnFinished(float radians);
    void waitUntilMoveFinished(float meters);

private:
    Motion() = default; // private constructor

    // dependency pointers
    Encoders* mEncoders = nullptr;
    Gyroscope* mGyro = nullptr;
    Motors* mMotors = nullptr;

    // motion state
    float m_prevTargetLinear = 0.0f;
    float m_prevTargetAngular = 0.0f;
    float m_targetLinear = 0.0f;
    float m_targetAngular = 0.0f;
    const float WHEEL_BASE = 0.28f; // meters
};

// Singleton instance declaration
//extern Motion motion;