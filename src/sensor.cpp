#include"include/sensor.h"
#include<chrono>
#include<thread>
#include<random>
#include<iostream>

void RWA2::sensor::read_data(unsigned int duration){
    std::cout << "Sensor" << " " << model_<< " " << "gathering data for" << " " << duration << " " << "seconds" << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    int counter{0};
    float sensor_data_;
    while(counter<50){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(1.0, 30.0);
        sensor_data_ = dis(gen);
        data_[counter] = sensor_data_;
        counter++;
    }

}