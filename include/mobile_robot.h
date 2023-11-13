#pragma once
#include<string>
#include<vector>
#include<memory>
#include "include/battery.h"
#include "include/sensor.h"

/**
 * @brief namespace for the Assignment RWA2
 * 
 */
namespace RWA2{
/**
 * @brief Base Class mobile_robot
 * 
 */
    class mobile_robot
    {
    protected:
        /* protected attributes */
        std::pair<double,double> position_;
        double orientation_;
        double speed_{0.0};
        RWA2::battery battery_;
        std::vector<std::unique_ptr<RWA2::sensor>> sensors_ = {std::make_unique<RWA2::sensor>()};
        std::string model_;
        
        /*methods*/
        virtual void rotate(double angle);

    public:
        /*constructor*/
        mobile_robot(){}
        mobile_robot(double x,double y, double theta, std::string &model):position_{x,y},orientation_{theta},model_{model}{}

        /*accessors*/
        int get_orientation()const{
            return orientation_;
        }

        std::pair<double,double> get_position()const{
            return position_;
        }
        
        /*public methods*/
        virtual void move(double distance,double angle) = 0;
        virtual void print_status();
    };// class mobile_robots
    
}//namespace RWA2