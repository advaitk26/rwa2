#include"include/WheeledRobot.h"
#include<iostream>
#include<chrono>
#include<thread>

void RWA2::WheeledRobot::accelerate(double amount){
    while(speed_<= desired_speed_){
        speed_+= amount;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if(speed_== desired_speed_){
            std::cout << model_ << " " << "has reached the desired speed of" << " " << desired_speed_ << "m/s" <<'\n';
    
        }
    }
}

void RWA2::WheeledRobot::decelerate(double amount){
    while(speed_>0.0){
        speed_ -= amount;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void RWA2::WheeledRobot::brake(){
    speed_ = 0.0;
}

void RWA2::WheeledRobot::rotate(double angle){
    RWA2::mobile_robot::rotate(angle);
    std::cout << "WheeledRobot:: "<< model_ << "rotated " << angle << "degrees" << '\n';
}

void RWA2::WheeledRobot::print_status(){
    RWA2::mobile_robot::print_status();
    std::cout << "Number of wheels: " << number_of_wheels_ << '\n';
    std::cout << "Wheel Diameter: " << wheel_diameter_ << '\n';
    std::cout << "Desired Speed: " << desired_speed_ << '\n';
}

void RWA2::WheeledRobot::move(double distance,double angle){
    int time = distance-2;
    double max_distance_ = 100;
    double currentcharge_ = battery_.get_current_charge();
    if (distance>max_distance_){
        std::cout << "Error: value exceeding limit";
    }
    else{
        if (currentcharge_ >= distance){
            sensors_[0]->read_data(5);
            accelerate(2);
            std::this_thread::sleep_for(std::chrono::seconds(time));
            decelerate(2);
            brake();
            std::cout << model_ << " drove " << distance << "m" << '\n';
            print_status();

        }
        else{
            battery_.start_charging();
            sensors_[0]->read_data(5);
            accelerate(2);
            std::this_thread::sleep_for(std::chrono::seconds(time));
            decelerate(2);
            brake();
            std::cout << model_ << " drove " << distance << "m" << '\n';
            print_status();
        }
    }

}