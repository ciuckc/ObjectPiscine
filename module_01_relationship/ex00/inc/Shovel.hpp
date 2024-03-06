#pragma once

#include "Tool.hpp"
#include "Worker.hpp"

class Shovel : public Tool {
 public:
  Shovel() = default;
  Shovel(const Shovel&) = delete;
  Shovel& operator=(const Shovel&) = delete;
  Shovel(Shovel&&) = default;
  Shovel& operator=(Shovel&&) = default;
  ~Shovel() override;

  void use() override;
};
