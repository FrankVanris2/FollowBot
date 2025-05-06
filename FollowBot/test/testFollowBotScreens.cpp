#include <unity.h>
#include "IdleScreen.h"
#include "MapScreen.h"
#include "ManualControlScreen.h"

// Mock TFT_eSPI object
class MockTFT : public TFT_eSPI {
public:
    void fillScreen(uint16_t color) {
        // Mock implementation for testing
    }
};

MockTFT mockTFT;

// Test IdleScreen
void testIdleScreenSetup() {
    IdleScreen idleScreen;
    idleScreen.setup(mockTFT);
    TEST_PASS_MESSAGE("IdleScreen setup completed successfully.");
}

void testIdleScreenDraw() {
    IdleScreen idleScreen;
    idleScreen.setup(mockTFT); // Ensure setup is called before draw
    idleScreen.draw();
    TEST_PASS_MESSAGE("IdleScreen draw completed successfully.");
}

void testIdleScreenTouchEvent() {
    IdleScreen idleScreen;
    idleScreen.setup(mockTFT);
    bool result = idleScreen.touchScreenEvent(10, 10); // Example coordinates
    TEST_ASSERT_FALSE(result); // Assuming no touchable components are initialized
}

// Test MapScreen
void testMapScreenSetup() {
    MapScreen mapScreen;
    mapScreen.setup(mockTFT);
    TEST_PASS_MESSAGE("MapScreen setup completed successfully.");
}

void testMapScreenDraw() {
    MapScreen mapScreen;
    mapScreen.setup(mockTFT);
    mapScreen.draw();
    TEST_PASS_MESSAGE("MapScreen draw completed successfully.");
}

void testMapScreenTouchEvent() {
    MapScreen mapScreen;
    mapScreen.setup(mockTFT);
    bool result = mapScreen.touchScreenEvent(20, 20); // Example coordinates
    TEST_ASSERT_FALSE(result);
}

// Test ManualControlScreen
void testManualControlScreenSetup() {
    ManualControlScreen manualControlScreen;
    manualControlScreen.setup(mockTFT);
    TEST_PASS_MESSAGE("ManualControlScreen setup completed successfully.");
}

void testManualControlScreenDraw() {
    ManualControlScreen manualControlScreen;
    manualControlScreen.setup(mockTFT);
    manualControlScreen.draw();
    TEST_PASS_MESSAGE("ManualControlScreen draw completed successfully.");
}

void testManualControlScreenTouchEvent() {
    ManualControlScreen manualControlScreen;
    manualControlScreen.setup(mockTFT);
    bool result = manualControlScreen.touchScreenEvent(30, 30); // Example coordinates
    TEST_ASSERT_FALSE(result);
}

// Main function to run tests
int main(int argc, char **argv) {
    UNITY_BEGIN();

    // IdleScreen tests
    RUN_TEST(testIdleScreenSetup);
    RUN_TEST(testIdleScreenDraw);
    RUN_TEST(testIdleScreenTouchEvent);

    // MapScreen tests
    RUN_TEST(testMapScreenSetup);
    RUN_TEST(testMapScreenDraw);
    RUN_TEST(testMapScreenTouchEvent);

    // ManualControlScreen tests
    RUN_TEST(testManualControlScreenSetup);
    RUN_TEST(testManualControlScreenDraw);
    RUN_TEST(testManualControlScreenTouchEvent);

    return UNITY_END();
}