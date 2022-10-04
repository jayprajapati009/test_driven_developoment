/**
 * @file pid.hpp
 * @author Joshua Gomes (GitID:joshuag1214),Venkata Sairam Polina (GitID:sairampolina)
 * @brief 
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INCLUDE_PID_HPP_
#define INCLUDE_PID_HPP_

/**
 * @brief PID controller(Class) meant to control the velocity of the robot  
 * 
 */

class PID{
 private:
    double kp;
    double ki;
    double kd;
    double dt;
    double lowest_velocity;
    double largest_velocity;

 public:
    /**
        * @brief PID constructor
        * 
        * @param kp proportional gain
        * @param kd derivative gain
        * @param ki integral gain
        * @param dt time step
        * @param largest_velocity largest velocity possible 
        * @param lowest_velocity  lowest velocity possible
        * @return PID:: none
        */
    PID(double kp, double kd, double ki, double dt,
            double largest_velocity, double lowest_velocity);

    /**
        * @brief Destroy the PID object
        * 
        */
    ~PID();

    /**
        * @brief The user inputs the desired velocity and present velocity into this function.
        * This function should calculate error= desired_velocity - present_velociy  which is taken in to PID equation.
        * The output of PID equation is the change in velocity, that needs to be added to the present velocity 
        * 
        * @param desired_velocity the velocity that you want the robot to be set at  
        * @param present_velocity current velocity of the robot
        * @return double: change in velocity  after PID calculation ,which needs to be added to present velocity to  take it close to desired velocity (basically minimizing the error).
        */
    double calculate(double desired_velocity, double present_velocity);
};

#endif  // INCLUDE_PID_HPP_
