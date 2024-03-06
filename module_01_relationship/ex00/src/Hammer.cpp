#include "Hammer.hpp"

Hammer::~Hammer() {
  if (this->worker_ != nullptr) {
    this->worker_->takeTool(this);
  }
}

void Hammer::use() {
  if (this->worker_ != nullptr) {
    ++this->num_of_uses_;
    std::cout << "Hammer is being used [" << this->num_of_uses_ << "]\n";
  }
}
