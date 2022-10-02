#include <iostream>
#include <cmath>


/**
 * @file main.cpp
 * @author Joshua Gomes (GitID:joshuag1214),Venkata Sairam Polina (GitID:sairampolina)
 * @brief 
 * @version 0.1
 * @date 2022-09-29
 * //TODO stub
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Computes a new velocity given target set point and actual velocity
 * 
 */


class PID {
    private:
        double kp;
        double ki;
        double kd;
        double dt;
        double largest_velocity;
        double lowest_velocity;

    public:
        PID() {
            std::cout << "Enter Kp: ";
            std::cin >> kp;
            std::cout << "Enter Ki: ";
            std::cin >> ki;
            std::cout << "Enter Kd: ";
            std::cin >> kd;
            std::cout << "Enter maximum velocity: ";
            std::cin >> largest_velocity;
            std::cout << "Enter minimum velocity: ";
            std::cin >> lowest_velocity;
        }

        ~PID() {
        }

        double calculate(double setpoint, double pv, double dt) {

            double pre_error = 0;
            double integral = 0;

            // Calculating the error
            double error = setpoint - pv;

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

            if( output > largest_velocity ) {
                output = largest_velocity;
            }
            else if( output < lowest_velocity ) {
                output = lowest_velocity;
            }

            // Save error to previous error
            pre_error = error;

            return output;
        }

};

int main(){
    PID pid;
    double val = 20;
    double dt = 0.1;
    for (int i = 0; i < 100; i++) {
        double inc = pid.calculate(0, val, dt);
        printf("val:% 7.3f inc:% 7.3f\n", val, inc);
        val += inc;
    }
    return 0;
}
