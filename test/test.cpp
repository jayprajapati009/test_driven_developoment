#include <gtest/gtest.h>

#include "../include/pid.hpp"

PID pid(0.1,0.01,0.5,0.1,100,0);

TEST(pid_controller_test, output_test)
 { EXPECT_NEAR(pid.calculate(0, 30), -7.5, 0.0001); }

TEST(pid_controller_test, output_test_2)
 { EXPECT_NEAR(pid.calculate(0, 20), -5, 0.0001); }




