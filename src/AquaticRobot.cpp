#include"include/AquaticRobot.h"
#include<chrono>
#include<thread>
#include<iostream>

void RWA2::AquaticRobot::dive(double depth){
    int dive_time_fins_ = depth/2;
    int dive_time_no_fins_ = depth/1;
    if (is_diving_ == false){
        if(has_fins_ == true){
            std::this_thread::sleep_for(std::chrono::seconds(dive_time_fins_));
            depth_ = depth;
            is_diving_ = true;
        }
        else if(has_fins_ == false){
            std::this_thread::sleep_for(std::chrono::seconds(dive_time_no_fins_));
            depth_ = depth;
            is_diving_ = true;
        }
    }
}

void RWA2::AquaticRobot::surface(){
    int surfaceing_time_fins = depth_/4;
    int surfaceing_time_no_fins = depth_/2;
    if (is_diving_ = true){
        if(has_fins_ == true){
            std::this_thread::sleep_for(std::chrono::seconds(surfaceing_time_fins));
            depth_ = 0.0;
            is_diving_ = false;
            battery_.start_charging();
        }
        else if(has_fins_ == false){
            std::this_thread::sleep_for(std::chrono::seconds(surfaceing_time_no_fins));
            depth_ = 0.0;
            is_diving_ = false;
            battery_.start_charging();

        }
    }
}

void RWA2::AquaticRobot::rotate(double angle){
    RWA2::mobile_robot::rotate(angle);
    std::cout << "AquaticRobot:: "<< model_ << "rotated " << angle << "degrees" << '\n';
}

void RWA2::AquaticRobot::print_status(){
    RWA2::mobile_robot::print_status();
    std::cout << "Has fins: " << has_fins_ << '\n';
    std::cout << "Depth: " << depth_ << '\n';
    std::cout << "Is Diving: " << is_diving_ << '\n';
}

void RWA2::AquaticRobot::move(double distance,double angle){
    double max_distance_ = 100;
    double currentcharge_ = battery_.get_current_charge();
    if (distance>max_distance_){
        std::cout << "Error: value exceeding limit";
    }
    else{
        if (currentcharge_ >= distance){
            sensors_[0]->read_data(5);
            dive(distance/2);
            rotate(angle);
            surface();
            std::cout << model_ << " reached a depth of " << distance << " " << " meters and then surfaced" << '\n';
            print_status();

        }
        else{
            battery_.start_charging();
            sensors_[0]->read_data(5);
            dive(distance/2);
            rotate(angle);
            surface();
            std::cout << model_ << " reached a depth of " << distance << " " << " meters and then surfaced" << '\n';
            print_status();
        }
    }

}