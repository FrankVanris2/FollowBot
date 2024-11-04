#include "unity.h"

void setUp(void) {
    // Set up code here (if needed)
}

void tearDown(void) {
    // Clean up code here (if needed)
}

int add(int a, int b) { return a + b; }

void test_example_function(void) {
    int result = add(40, 2); // Replace with your actual function
    TEST_ASSERT_EQUAL(42, result); // Replace with the expected result
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_example_function);
    return UNITY_END();
}