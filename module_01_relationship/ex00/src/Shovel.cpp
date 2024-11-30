#include "Shovel.hpp"

#include <iostream>

void Shovel::use() {
  ++this->num_of_uses_;
  std::cout << "Shovel was used [" << this->num_of_uses_ << "] times\n";
}
