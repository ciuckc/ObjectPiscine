#pragma once

#include <cstdint>

#include "ITool.hpp"

class Hammer : public ITool {
 public:
  Hammer() = default;
  Hammer(Hammer&&) = default;
  Hammer(const Hammer&) = delete;
  Hammer& operator=(Hammer&&) = default;
  Hammer& operator=(const Hammer&) = delete;
  ~Hammer() = default;

  void use() override;

 private:
  std::uint64_t num_of_uses_;
};
