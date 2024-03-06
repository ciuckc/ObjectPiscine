#include <stdint.h>

#include <ostream>
#include <stdexcept>

#include "Bank.hpp"

Bank::Account::Account(const double initial_value) : value_(initial_value) {
  if (initial_value < 0) {
    throw std::invalid_argument("Value can't be negative.");
  }
}

const uint32_t& Bank::Account::getId() const {
  return this->id_;
}

const uint32_t& Bank::Account::getValue() const {
  return this->value_;
}

std::ostream& operator<<(std::ostream& os, const Bank::Account& obj) {
  os << "[" << obj.getId() << "] - [" << obj.getValue() << "]";
  return os;
}
