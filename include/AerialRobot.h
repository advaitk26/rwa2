#pragma once
#include"include/mobile_robot.h"
#include<string>

/**
 * @brief namespace for the Assignment RWA2
 * 
 */
namespace RWA2{
/**
 * @brief Derived class AerialRobot
 * 
 */
    class AerialRobot: public mobile_robot
    {
    private:

    /*private Attributes*/

        bool has_wings_;
        double altitude_{0.0};
        bool is_flying_=false;

    /*private Methods*/

        void take_off(double altitude);
        void land();

    protected:

    /*protected Methods*/

        virtual void rotate(double angle) override;

    public:

    /*Constructor*/

        AerialRobot(double x, double y, double theta, std::string name, bool wings):mobile_robot(x,y,theta,name),has_wings_{wings}{}
    
    /*public Methods*/

        virtual void move(double distance,double angle) override;
        virtual void print_status() override;
    };//class Aerial Robot
}//namespace RWA2