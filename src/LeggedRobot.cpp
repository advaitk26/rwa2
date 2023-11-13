#include"include/LeggedRobot.h"
#include<iostream>

void RWA2::LeggedRobot::kick(){
    std::cout<< model_ << " " << "kicks with a strength of" << " " << leg_strength_;
}

void RWA2::LeggedRobot::jump(double amount){
    double conversion_to_cm_ = amount*100.0;
    double height_ = leg_strength_*conversion_to_cm_;
    std::cout<< model_ << " " << "jumps at a height of" << " " << height_ << "cm above the ground"<<'\n';
}

void RWA2::LeggedRobot::rotate(double angle){
    RWA2::mobile_robot::rotate(angle);
    std::cout << "LeggedRobot:: "<< model_ << "rotated " << angle << "degrees" << '\n';
}

void RWA2::LeggedRobot::print_status(){
    RWA2::mobile_robot::print_status();
    std::cout << "Height: " << height_<< '\n';
    std::cout << "Leg Strength: " << leg_strength_ << '\n';
    std::cout << "No. of Legs: " << number_of_legs_ << '\n';
}

void RWA2::LeggedRobot::move(double distance,double angle){
    double max_distance_ = 10;
    double currentcharge_ = battery_.get_current_charge();
    if (distance>max_distance_){
        std::cout << "Error: value exceeding limit";
    }
    else{
        if (currentcharge_ >= (distance*100)){
            sensors_[0]->read_data(5);
            rotate(angle);
            jump(distance);
            kick();
            print_status();

        }
        else{
            battery_.start_charging();
            sensors_[0]->read_data(5);
            rotate(angle);
            jump(distance);
            kick();
            print_status();
        }
    }

}