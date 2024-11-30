#pragma once

#include <array>

#include "Gear.hpp"
#include "Singleton.hpp"

class GearLever : public Singleton<GearLever> {
  friend class Singleton<GearLever>;

 public:
  GearLever(const GearLever&) = delete;
  GearLever(GearLever&&) = delete;
  GearLever& operator=(const GearLever&) = delete;
  GearLever& operator=(GearLever&&) = delete;

  void change(){};
  Gear* activeGear() { return &(gears_.at(level_)); }
  [[nodiscard]] const Gear* activeGear() const { return &(gears_.at(level_)); }

 protected:
  GearLever() noexcept = default;
  ~GearLever() noexcept override = default;

 private:
  // this should be passed as an NTTP
  static constexpr unsigned int kMaxGearLevel = 5;

  unsigned int level_{};
  std::array<Gear, kMaxGearLevel> gears_{};
};
