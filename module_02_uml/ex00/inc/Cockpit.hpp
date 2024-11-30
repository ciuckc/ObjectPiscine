#pragma once

#include "GearLever.hpp"
#include "Pedal.hpp"
#include "SteerWheel.hpp"

class Cockpit {
 public:
 private:
  Pedal pedal_{};
  SteerWheel steering_wheel_{};
  GearLever gear_lever_{};
};
