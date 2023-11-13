#include"include/AerialRobot.h"
#include<chrono>
#include<thread>
#include<iostream>


void RWA2::AerialRobot::take_off(double altitude){
    int take_off_time_wings_ = altitude/3;
    int take_off_time_no_wings_ = altitude/1.5;
    if (is_flying_ == false){
        if(has_wings_ == true){
            std::this_thread::sleep_for(std::chrono::seconds(take_off_time_wings_));
            altitude_ = altitude;
            is_flying_ = true;
        }
        else if(has_wings_ == false){
            std::this_thread::sleep_for(std::chrono::seconds(take_off_time_no_wings_));
            altitude_ = altitude;
            is_flying_ = true;
        }
    }
}

void RWA2::AerialRobot::land(){
    int landing_time_wings = altitude_/4;
    int landing_time_no_wings = altitude_/2;
    if (is_flying_ = true){
        if(has_wings_ == true){
            std::this_thread::sleep_for(std::chrono::seconds(landing_time_wings));
            altitude_ = 0.0;
            is_flying_ = false;
        }
        else if(has_wings_ == false){
            std::this_thread::sleep_for(std::chrono::seconds(landing_time_no_wings));
            altitude_ = 0.0;
            is_flying_ = false;
        }
    }

}

void RWA2::AerialRobot::rotate(double angle){
    RWA2::mobile_robot::rotate(angle);
    std::cout << "AerialRobot:: "<< model_ << "rotated " << angle << "degrees" << '\n';
}

void RWA2::AerialRobot::print_status(){
    RWA2::mobile_robot::print_status();
    std::cout << "Has wings: " << has_wings_ << '\n';
    std::cout << "Altitude: " << altitude_ << '\n';
    std::cout << "Is Flying: " << is_flying_ << '\n';
}

void RWA2::AerialRobot::move(double distance,double angle){
    double max_distance_ = 50;
    double currentcharge_ = battery_.get_current_charge();
    if (distance>max_distance_){
        std::cout << "Error: value exceeding limit";
    }
    else{
        if (currentcharge_ >= distance){
            sensors_[0]->read_data(5);
            take_off(distance/2);
            rotate(angle);
            land();
            std::cout << model_ << " reached an altitude of " << distance << " " << " meters and then landed" << '\n';
            print_status();

        }
        else{
            battery_.start_charging();
            sensors_[0]->read_data(5);
            take_off(distance/2);
            rotate(angle);
            land();
            std::cout << model_ << " reached an altitude of " << distance << " " << " meters and then landed" << '\n';
            print_status();
        }
    }

}