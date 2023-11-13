#pragma once
#include"include/mobile_robot.h"
#include<string>
/**
 * @brief namespace for the Assignment RWA2
 * 
 */
namespace RWA2
{
/**
 * @brief Derived class WheeledRobot
 * 
 */
    class WheeledRobot: public mobile_robot{
        private:

        /*private Attributes*/

            int number_of_wheels_;
            double wheel_diameter_;
            double desired_speed_;

        /*private Methods*/

            void accelerate(double amount);
            void decelerate(double amount);
            void brake();
        protected:

        /*protected Methods*/

            virtual void rotate(double angle) override;
        public:

        /*Constructor*/

            WheeledRobot(double x, double y, double theta, std::string name,int wheels = 2,double diameter,double speed):mobile_robot(x,y,theta,name),number_of_wheels_{wheels},wheel_diameter_{diameter},desired_speed_{speed}{}
        /*public Methods*/    

            virtual void move(double distance,double angle) override;
            virtual void print_status() override;
    };//class WheeledRobot
    
} //namespace RWA2
