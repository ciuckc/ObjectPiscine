#pragma once

#include "Transmission.hpp"

class Crankshaft {
 public:
  void receiveForce(float p_volume) { (void)p_volume; }

 private:
  Transmission* transmission_{};
};
