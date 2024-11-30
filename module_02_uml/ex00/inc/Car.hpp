#pragma once

#include "BrakeController.hpp"
#include "Cockpit.hpp"
#include "Direction.hpp"
#include "Electronics.hpp"
#include "Motor.hpp"
#include "Transmission.hpp"
class Car {
 public:
 private:
  BrakeController brake_controller_{};
  Direction direction_{};
  Transmission transmission_{};
  Motor motor_{};
  Electronics electronics_{};
  Cockpit cockpit_{};
};
