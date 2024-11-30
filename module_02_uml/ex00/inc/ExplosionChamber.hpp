#pragma once

#include "Crankshaft.hpp"

class ExplosionChamber {
 public:
  void fill(float p_volume) { (void)p_volume; }

 private:
  Crankshaft* crankshaft_{};
};
