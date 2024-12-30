#pragma once

#include <cstdint>

#include "Tool.hpp"

class Hammer : public Tool {
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
