/*
By: Frank Vanris
Date: 11/5/2024
Desc: Unit Testing environment example for the Robotics side
*/

#include "unity.h"

void setUp(void) {
    // Set up code here (if needed)
}

void tearDown(void) {
    // Clean up code here (if needed)
}

//unit test functions
int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int divide(int a, int b) { 
    if (b == 0) {
        return - 1;
    }
    return a / b; 
}

int multiply(int a, int b) { return a * b;}



//This function is meant to test out the above 2 functions
void test_example_function(void) {
    int result = add(40, 2);
    TEST_ASSERT_EQUAL(42, result); 

    result = sub(2, 2);
    TEST_ASSERT_EQUAL(0, result);

    result = divide(20, 2);
    TEST_ASSERT_EQUAL(10, result);

    result = divide(2, 0);
    TEST_ASSERT_EQUAL(-1, result);

    result = multiply(4, 8);
    TEST_ASSERT_EQUAL(32, result);
}



int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_example_function);
    return UNITY_END();
}