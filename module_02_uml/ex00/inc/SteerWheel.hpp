#pragma once

#include "DAE.hpp"

class SteerWheel {
 public:
  void turn(float p_angle) {
    if (dae_ != nullptr) {
      dae_->use(p_angle);
    }
  }

 private:
  DAE* dae_{};
};
