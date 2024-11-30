#pragma once

#include <vector>

#include "Wheel.hpp"

class Transmission {
 public:
  void activate(float p_force) { (void)p_force; }

 private:
  std::vector<Wheel*> system_{};
};
