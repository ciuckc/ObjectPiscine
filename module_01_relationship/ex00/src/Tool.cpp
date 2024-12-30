#include "Tool.hpp"
#include "Worker.hpp"

void Tool::assignToWorker(Worker* new_worker) {
  if (new_worker == nullptr) {
    return;
  }
  if (this->worker_ == new_worker) {
    return;
  }
  if (this->worker_ != nullptr) {
    this->worker_->takeTool(this);
  }
  this->worker_ = new_worker;
  new_worker->giveTool(this);
}

void Tool::takeFromCurrentWorker() {
  // this is terrible....
  if (worker_ != nullptr) {
    // swap so we don't cause infinite recursion
    auto* tmp = this->worker_;
    this->worker_ = nullptr;
    tmp->takeTool(this);
  }
}
