#include <iostream>
#include <memory>
#include <vector>

#include "include/mobile_robot.h"
#include "include/AquaticRobot.h"
#include "include/AerialRobot.h"
#include "include/LeggedRobot.h"
#include "include/WheeledRobot.h"

void move_robot(const std::vector<std::unique_ptr<RWA2::mobile_robot>>& robots) {
for (const auto& robot : robots)
  robot->move(5, 10);
}

int main() {
  std::vector<std::unique_ptr<RWA2::mobile_robot>> mobile_robots;

std::unique_ptr<RWA2::mobile_robot> aquatic_ptr =
    std::make_unique<RWA2::AerialRobot>(2.5, 5.5, 45.0, 'HoloOcean', false);

  std::unique_ptr<RWA2::mobile_robot> aerial_ptr =
      std::make_unique<RWA2::AerialRobot>(2.5, 5.5, 45.0, 'Crazyflie', false);

  std::unique_ptr<RWA2::mobile_robot> legged_ptr =
      std::make_unique<RWA2::LeggedRobot>(3.5, 6.5, 45.0, 'Atlas',0.5,2,2);

  std::unique_ptr<RWA2::mobile_robot> wheeled_ptr =
      std::make_unique<RWA2::WheeledRobot>(4.5, 7.5, 0.0, 'Turtlebot',2,2.0,2.0);

  mobile_robots.push_back(std::move(aerial_ptr));
  mobile_robots.push_back(std::move(legged_ptr));
  mobile_robots.push_back(std::move(wheeled_ptr));

  move_robot(mobile_robots);
}