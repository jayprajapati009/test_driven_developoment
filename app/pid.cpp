/**
 * @file pid.cpp
 * @author Jay Prajapati (jayp@umd.edu)
 * @brief 
 * @version 1.1
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _PID_SOURCE_
#define _PID_SOURCE_

#include <iostream>
#include <cmath>
#include "../include/pid.hpp"

/**
 * @brief Construct a new PID::PID object
 * 
 * @param kp 
 * @param kd 
 * @param ki 
 * @param dt 
 * @param largest_velocity 
 * @param lowest_velocity 
 */

PID::PID(double kp_, double kd_, double ki_, double dt_,double largest_velocity_, double lowest_velocity_):kp (kp_),kd (kd_),ki(ki_) ,dt(dt_),largest_velocity(largest_velocity_),lowest_velocity(lowest_velocity_){
   
}

/**
 * @brief 
 * 
 * @param desired_velocity 
 * @param present_velocity 
 * @return double 
 */

double PID::calculate(double desired_velocity, double present_velocity) {
    double pre_error = 0;
    double integral = 0;

    // Calculating the error
    double error = desired_velocity - present_velocity;

    // The value for the Proportional term
    double Pout = kp * error;

    // The value for the Integral term
    integral += error * dt;
    double Iout = ki * integral;

    // Finding Derivative term
    double derivative = (error - pre_error) / dt;
    double Dout = kd * derivative;

    // Calculating total output
    double output = Pout + Iout + Dout;

    // if (output > largest_velocity) {
    //     output = largest_velocity;
    // } else if (output < lowest_velocity) {
    //     output = lowest_velocity;
    // } else {
    //     output = output;
    // }

    // Save error to previous error
    pre_error = error;

    return output;
}

/**
 * @brief Destroy the PID::PID object
 * 
 */
PID::~PID() {}

#endif
