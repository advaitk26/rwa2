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
 * @brief Derived class Legged Robot
 * 
 */
    class LeggedRobot:public mobile_robot{
        private:

        /*private Attributes*/

            double height_;
            int leg_strength_;
            int number_of_legs_;

        /*private Methods*/

            void kick();
            void jump(double amount);

        protected:

        /*protected Methods*/

            virtual void rotate(double angle) override;
        
        public:

        /*Constructor*/

            LeggedRobot(double x, double y, double theta, std::string name,double height, int strength, int legs = 2):mobile_robot(x,y,theta,name),height_{height},leg_strength_{strength},number_of_legs_{legs}{}
        
        /*public Metods*/

            virtual void move(double distance,double angle) override;
            virtual void print_status() override;
    };//class Legged Robot
    
} //namespace RWA2
