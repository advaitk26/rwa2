#include "include/mobile_robot.h"
#include<iostream>

void RWA2::mobile_robot::rotate(double angle){
    double angle_offset{angle};
    if(angle_offset>0.0)
    {
        orientation_ += angle_offset;
    }
    else if (angle_offset<0.0)
    {
        orientation_ -= angle_offset;
    } 
}

void RWA2::mobile_robot::print_status(){
    std::cout << "================\n";
    std::cout
      << "Position: (" << position_.first << ", "
      << position_.second << "), Orientation: " << orientation_
      << ", Speed: " << speed_ << "\n";
}


