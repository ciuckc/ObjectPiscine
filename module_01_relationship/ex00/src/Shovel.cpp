#include "Shovel.hpp"

#include "Tool.hpp"

Shovel::~Shovel() {
  if (this->worker_ != nullptr) {
    worker_->takeTool(this);
  }
}

void Shovel::use() {
  if (worker_ != nullptr) {
    ++this->num_of_uses_;
    std::cout << "Shovel was used [" << this->num_of_uses_ << "] times\n";
  }
}
