#pragma once

#include "ExplosionChamber.hpp"
#include "LinkablePart.hpp"
class Injector : LinkablePart {
 public:
  void execute(float pressure) override { explosion_chamber_->fill(pressure); }

 private:
  ExplosionChamber* explosion_chamber_{};
};
