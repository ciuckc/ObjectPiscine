#pragma once

#include "Direction.hpp"
class DAE {
 public:
  void use(float p_angle) {
    if (direction_ != nullptr) {
      direction_->turn(p_angle);
    }
  }

 private:
  float force_{};
  Direction* direction_{};
};
