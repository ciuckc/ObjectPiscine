#pragma once

#include "Wheel.hpp"

class Brake {
 public:
  void execute(float p_force) {
    if (wheel_ != nullptr) {
      wheel_->executeRotation(p_force);
    }
  }

  void attackWheel(Wheel* wheel) {
    if (wheel == nullptr) {
      this->wheel_ = wheel;
    }
  }

 private:
  Wheel* wheel_{};
};
