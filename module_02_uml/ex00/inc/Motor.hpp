#pragma once

#include "Crankshaft.hpp"
#include "ExplosionChamber.hpp"
#include "Injector.hpp"
#include "Transmission.hpp"
class Motor {
 public:
  void connectToTransmission(Transmission* p_transmission) { (void)p_transmission; }

 private:
  Injector injector_{};
  ExplosionChamber explosion_chamber_{};
  Crankshaft crankshaft_{};
};
