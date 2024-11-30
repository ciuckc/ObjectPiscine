#pragma once

#include <vector>

#include "Wheel.hpp"

class Direction {
 public:
  void turn(float p_angle) {
    for (auto wheel : wheels_) {
      wheel.executeRotation(p_angle);
    }
  }

 private:
  std::vector<Wheel> wheels_{};
};
