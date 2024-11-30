#pragma once

#include <vector>

#include "Brake.hpp"
#include "LinkablePart.hpp"

class BrakeController : LinkablePart {
 public:
  void execute(float p_pression) override {
    for (auto brake : brakes_) {
      brake.execute(p_pression);
    }
  }

 private:
  std::vector<Brake> brakes_{};
};
