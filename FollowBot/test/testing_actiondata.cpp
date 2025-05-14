/*
By: Frank Vanris
Date: 5/13/2025
Desc: Unit Tests for FollowBotClient's handleActionData function
*/

#include <unity.h>
#include "MockArduino.h"
#include <string>

// We'll create mock version of dependencies to isolate our testing
// Mock version of followBotManager
class MockFollowBotManager {
public:
    String currentControl;
    void setCurrentControl(const String& control) {
        currentControl = control;
    }
    String getCurrentControl() const {
        return currentControl;
    }
};

// Mock version of Motors
class MockMotors {
public:
    String currentDirection;
    void setDirection(const String& direction) {
        currentDirection = direction;
    }
    String getDirection() const {
        return currentDirection;
    }
};

// Global mock objects
MockFollowBotManager mockManager;
MockMotors mockMotors;

// Redefine external references to use our mocks
#define followBotManager mockManager
#define myMotors mockMotors

// Constants needed from MotorControlStates.h
const String FOLLOWING = "FOLLOWING";
const String MANUAL = "MANUAL";
const String MAPPING = "MAPPING";
const String IDLE = "IDLE";

// The function we're testing (copied from FollowBotClient.cpp with print statements removed)
void handleActionData(String dataString) {
    // Trim any whitespace
    dataString.trim();

    // Find the first comma (if any)
    int firstComma = dataString.indexOf(',');

    // Extract mode (everything before first comma, or the entire string if no comma)
    String mode = (firstComma >= 0) ? dataString.substring(0, firstComma) : dataString;

    // Always update control mode first
    if (mode == FOLLOWING || mode == MANUAL || mode == MAPPING) {
        // Update the robot's control mode
        followBotManager.setCurrentControl(mode);

    }

    // Process any additional parameters based on the mode
    if (firstComma >= 0) {
        if (mode == MANUAL) {
            // For manual mode, everything after the comma is the direction command
            String direction = dataString.substring(firstComma + 1);
            if (direction == "Forward" || direction == "Backward" || direction == "Left" || direction == "Right" || direction == "Stop") {
                // Set motor direction based on the command
                myMotors.setDirection(direction);
            } 
        } 
        else if (mode == MAPPING) {
            // For mapping mode, we expect latitude and longitude values
            String remainder = dataString.substring(firstComma + 1);
            int secondComma = remainder.indexOf(',');

            if (secondComma >= 0) {
                // Extract latitude and longitude from the remainder
                String latStr = remainder.substring(0, secondComma);
                String lonStr = remainder.substring(secondComma + 1);

                // setting the coordinates.
                float lat = latStr.toFloat();
                float lon = lonStr.toFloat();

                // Store for testing
                mockManager.setCurrentControl(MAPPING + "," + String(lat, 6) + "," + String(lon, 6));

            }
        }
    }
    // Handle FOLLOWING mode - no additional parameters needed
    else if (mode == FOLLOWING) {
        // No additional parameters needed for FOLLOWING mode
    }
}

// Test setup function - runs before each test
void setUp(void) {
    // Reset our mock objects
    mockManager.currentControl = "IDLE";
    mockMotors.currentDirection = "STOP";
}

// Test teardown function - runs after each test
void tearDown(void) {
    // Clean up if needed
}

// Test for simple FOLLOWING mode with no paremeters
void test_following_mode(void) {
    // Prepare
    String testInput = "FOLLOWING";

    // Act
    handleActionData(testInput);

    // Assert
    TEST_ASSERT_EQUAL_STRING("FOLLOWING", mockManager.getCurrentControl().c_str());

}

// Test for MANUAL mode with direction command 1
void test_manual_mode_1(void) {
    // Prepare
    String testInput = "MANUAL,Forward";

    // Act 
    handleActionData(testInput);

    // Assert
    TEST_ASSERT_EQUAL_STRING("MANUAL", mockManager.getCurrentControl().c_str());
    TEST_ASSERT_EQUAL_STRING("Forward", mockMotors.getDirection().c_str());
}

// Test for MANUAL mode with direction command 2
void test_manual_mode_2(void) {
    // Prepare
    String testInput = "MANUAL,Backward";

    // Act 
    handleActionData(testInput);

    // Assert
    TEST_ASSERT_EQUAL_STRING("MANUAL", mockManager.getCurrentControl().c_str());
    TEST_ASSERT_EQUAL_STRING("Backward", mockMotors.getDirection().c_str());
}

// Test for MANUAL mode with direction command 3 
void test_manual_mode_3(void) {
    // Prepare
    String testInput = "MANUAL,Left";

    // Act 
    handleActionData(testInput);

    // Assert
    TEST_ASSERT_EQUAL_STRING("MANUAL", mockManager.getCurrentControl().c_str());
    TEST_ASSERT_EQUAL_STRING("Left", mockMotors.getDirection().c_str());
}

// Test for MANUAL mode with direction command 4
void test_manual_mode_4(void) {
    // Prepare
    String testInput = "MANUAL,Right";

    // Act 
    handleActionData(testInput);

    // Assert
    TEST_ASSERT_EQUAL_STRING("MANUAL", mockManager.getCurrentControl().c_str());
    TEST_ASSERT_EQUAL_STRING("Right", mockMotors.getDirection().c_str());
}

// Test for MANUAL mode with direction command 5
void test_manual_mode_5(void) {
    // Prepare
    String testInput = "MANUAL,Stop";

    // Act 
    handleActionData(testInput);

    // Assert
    TEST_ASSERT_EQUAL_STRING("MANUAL", mockManager.getCurrentControl().c_str());
    TEST_ASSERT_EQUAL_STRING("Stop", mockMotors.getDirection().c_str());
}

// Test for Mapping mode with coordinates
void test_mapping_mode_with_coordinates(void) {
    // Prepare
    String testInput = "MAPPING,37.7749,-122.4195";

    // Act
    handleActionData(testInput);

    // Assert
    TEST_ASSERT_TRUE(mockManager.getCurrentControl().startsWith("MAPPING"));

    // Extract the coordinates from the control string
    String controlStr = mockManager.getCurrentControl();
    int firstComma = controlStr.indexOf(',');
    int secondComma = controlStr.indexOf(',', firstComma + 1);

    String latStr = controlStr.substring(firstComma + 1, secondComma);
    String lonStr = controlStr.substring(secondComma + 1);
    
    float lat = latStr.toFloat();
    float lon = lonStr.toFloat();

    // Test with a small epsilon for floating point comparison
    TEST_ASSERT_FLOAT_WITHIN(0.0001, 37.7749, lat);
    TEST_ASSERT_FLOAT_WITHIN(0.0001, -122.4195, lon);
}

// Test for invalid mode
void test_invalid_mode(void) {
    // Prepare
    String originalMode = mockManager.getCurrentControl();
    String testInput = "INVALID_MODE,SomeCommand";

    // Act
    handleActionData(testInput);
    
    // Assert - control mode should not change for invalid mode
    TEST_ASSERT_EQUAL_STRING(originalMode.c_str(), mockManager.getCurrentControl().c_str());
}

// Test for MANUAL mode with invalid direction 
void test_manual_mode_invalid_direction(void) {
    // Prepare
    String testInput = "MANUAL,INVALID_DIRECTION";

    // Act
    handleActionData(testInput);

    // Assert - mode should change but direction should be set to whatever was passed
    TEST_ASSERT_EQUAL_STRING("MANUAL", mockManager.getCurrentControl().c_str());
    TEST_ASSERT_EQUAL_STRING("STOP", mockMotors.getDirection().c_str());
}

// Test for MAPPING mode with missing second comma
void test_mapping_mode_missing_comma(void) {
    // Prepare
    String originalMapping = mockManager.getCurrentControl();
    String testInput = "MAPPING,37.7749";

    // Act
    handleActionData(testInput);

    // Assert - mode should change but no coordinates should be processed
    TEST_ASSERT_EQUAL_STRING("MAPPING", mockManager.getCurrentControl().c_str());
}

// Test for whitespace handling
void test_whitespace_handling(void) {
    // Prepare
    String testInput = "   FOLLOWING   ";

    // Act
    handleActionData(testInput);

    // Assert
    TEST_ASSERT_EQUAL_STRING("FOLLOWING", mockManager.getCurrentControl().c_str());
}

// Test for empty string
void test_empty_string(void) {
    // Prepare 
    String originalMode = mockManager.getCurrentControl();
    String testInput = "";

    // Act 
    handleActionData(testInput);
    
    // Assert - empty string should not change mode
    TEST_ASSERT_EQUAL_STRING(originalMode.c_str(), mockManager.getCurrentControl().c_str());
}

// Main function to run all tests
int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_following_mode);
    RUN_TEST(test_manual_mode_1);
    RUN_TEST(test_manual_mode_2);
    RUN_TEST(test_manual_mode_3);
    RUN_TEST(test_manual_mode_4);
    RUN_TEST(test_manual_mode_5);
    RUN_TEST(test_mapping_mode_with_coordinates);
    RUN_TEST(test_invalid_mode);
    RUN_TEST(test_manual_mode_invalid_direction);
    RUN_TEST(test_mapping_mode_missing_comma);
    RUN_TEST(test_whitespace_handling);
    RUN_TEST(test_empty_string);

    return UNITY_END();
}