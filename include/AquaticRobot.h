#pragma once
#include"include/mobile_robot.h"
#include<string>
/**
 * @brief namespace for Assignment RWA2
 * 
 */
namespace RWA2{
/**
 * @brief Derived class AquaticRobot
 * 
 */
    class AquaticRobot:public mobile_robot
    {
    private:

    /*private Attributes*/

        bool has_fins_;
        double depth_{0.0};
        bool is_diving_=false;

    /*private Methods*/

        void dive(double depth);
        void surface();
    
    protected:

    /*protected Methods*/

        virtual void rotate(double angle) override;

    public:

    /*Constructor*/

        AquaticRobot(double x, double y, double theta, std::string name,bool fins):mobile_robot(x,y,theta,name),has_fins_{fins}{}
    
    /*public Methods*/   

        virtual void move(double distance,double angle) override;
        virtual void print_status() override;
    };
    

    
}
