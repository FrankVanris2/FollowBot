#include "motion.h"

Motion motion;

void Motion::setVelocity(float linear, float angular) {
    if(!mEncoders || !mGyro || !mMotors) return;

    targetLinear = linear;
    targetAngular = angular;
}

void Motion::update() {
    if(!mEncoders || !mGyro || !mMotors) return;

    // differential speeds
    float left = targetLinear - (targetAngular * WHEEL_BASE / 2);
    float right = targetLinear + (targetAngular * WHEEL_BASE / 2);

    mMotors->setNormalizedSpeeds(left, right);
}

void Motion::waitUntilTurnFinished(float radians) {
    const float tolerance = 0.0349f; // ~2 degrees in radians
    float targetYaw = gyro.getYaw() + radians;

    while(fabs(gyro.getYaw() - targetYaw) > tolerance) {
        update(); // maintain current velocity
        delay(10);
    }
    setVelocity(0, 0);
    update();
}

void Motion::waitUntilMoveFinished(float meters) {
    const float tolerance = 0.05f; // meters
    float startDistance = encoders.getAverageDistance();

    while(fabs(encoders.getAverageDistance() - startDistance) < meters - tolerance) {
        update();
        delay(10);
    }
    setVelocity(0, 0);
    update();
}
