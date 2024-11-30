#include "Hammer.hpp"

#include <iostream>

void Hammer::use() {
  ++this->num_of_uses_;
  std::cout << "Hammer is being used [" << this->num_of_uses_ << "]\n";
}
