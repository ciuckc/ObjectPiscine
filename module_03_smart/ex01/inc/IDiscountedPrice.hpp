#pragma once

#include <cstddef>

class IDiscountedPrice {
 public:
  virtual std::size_t GetDiscountedPrice() const = 0;
};
