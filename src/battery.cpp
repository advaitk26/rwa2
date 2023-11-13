#include "include/battery.h"
#include<chrono>
#include<thread>
#include<iostream>

void RWA2::battery::start_charging(){
    bool status_ = get_charge_status();
    if(status_<capacity_){
        int amount_to_charge_ = 100 - current_charge_;
        int rate_charge = 4;
        int time_to_charge_ = amount_to_charge_/rate_charge;
        std::cout << "The battery has started charging"<<'\n';
        is_charging = true;
        std::chrono::seconds duration(time_to_charge_);
        std::this_thread::sleep_for(duration);
        current_charge_ = capacity_;
        if(current_charge_ == 100){
            stop_charging();
        }
        std::cout << "Sensor OSDome is charging" << '\n';
    }
}

void::RWA2::battery::stop_charging(){
    is_charging = false;
    std::cout << "Sensor OSDome is fully charged" << '\n';
}

void RWA2::battery::discharge(double amount){
    current_charge_ -= amount;
    std::cout << "Current charge:" << current_charge_ <<'\n';
}
    