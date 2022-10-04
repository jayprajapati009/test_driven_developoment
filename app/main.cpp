/**
 * @file main.cpp
 * @author Joshua Gomes (GitID:joshuag1214),Venkata Sairam Polina (GitID:sairampolina)
 * @brief 
 * @version 1.1
 * @date 2022-09-29
 * //TODO stub
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cmath>
#include "../include/pid.hpp"

/**
 * @brief Computes a new velocity given target set point and actual velocity
 * 
 * @return int 
 */
int main() {
    PID pid(1, 1, 1, 0.1, 1, -1);
    double val = 3;
    // std::cout << pid.calculate(0, val);
    for (int i = 0; i < 100; i++) {
        double inc = pid.calculate(0, val);
        std::cout << "Val: " << val << ", inc: " << inc << std::endl;
        val += inc;
    }
    return 0;
}
