#pragma once

#include <cstdint>

#include "Tool.hpp"

class Shovel : public Tool {
 public:
  Shovel() = default;
  Shovel(const Shovel&) = delete;
  Shovel& operator=(const Shovel&) = delete;
  Shovel(Shovel&&) = default;
  Shovel& operator=(Shovel&&) = default;
  ~Shovel() = default;

  void use() override;

 private:
  std::uint64_t num_of_uses_{};
};
