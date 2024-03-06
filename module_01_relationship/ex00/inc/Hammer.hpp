#pragma once

#include "Tool.hpp"

class Hammer : public Tool {
 public:
  Hammer() = default;
  Hammer(Hammer&&) = default;
  Hammer(const Hammer&) = delete;
  Hammer& operator=(Hammer&&) = default;
  Hammer& operator=(const Hammer&) = delete;
  ~Hammer() override;

  void use() override;
};
