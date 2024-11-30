#include "Worker.hpp"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "ITool.hpp"
#include "Position.hpp"
#include "Statistic.hpp"

Worker::Worker(std::string name) : name_{std::move(name)} {
  std::cout << "Worker " << this->name_ << " constructed!\n";
}

Worker::Worker() {
  std::cout << "Worker default constructed!\n";
}

Worker::Worker(Worker&& rhs) noexcept
    : name_{std::move(rhs.name_)}, stats_{std::move(rhs.stats_)}, pos_{std::move(rhs.pos_)} {
  rhs.pos_ = {};
  rhs.stats_ = {};
  std::cout << "Worker move constructed!\n";
}

Worker& Worker::operator=(Worker&& rhs) noexcept {
  if (this == &rhs) {
    return *this;
  }
  this->name_ = std::move(rhs.name_);
  this->pos_ = std::exchange(rhs.pos_, {});
  this->stats_ = std::exchange(rhs.stats_, {});
  std::cout << "Worker move assigned!\n";
  return *this;
}

Worker::~Worker() {
  for (const auto workshop : this->workshops_) {
    workshop->unsubscribe(this);
  }
}

void Worker::subscribeToWorkshop(IWorkshop* workshop) {
  if (const auto iter = std::ranges::find(this->workshops_, workshop); iter != this->workshops_.end()) {
    std::cout << "Worker, " << this->name_ << ", is already subscribed to workshop!\n";
    return;
  }
  workshop->subscribe(this);
  this->workshops_.push_back(workshop);
}

void Worker::unsubscribeFromWorkshop(IWorkshop* workshop) {
  const auto iter = std::ranges::find(this->workshops_, workshop);
  if (iter == this->workshops_.end()) {
    std::cout << "Worker, " << this->name_ << ", is not subscribed to this workshop!\n";
    return;
  }
  workshop->unsubscribe(this);
  this->workshops_.erase(iter);
}

std::ostream& operator<<(std::ostream& out, const Worker& obj) {
  out << "Position: " << obj.getPosition() << '\n';
  out << "Statistic: " << obj.getStatistic() << '\n';
  return out;
}

void Worker::giveTool(ITool* tool) {}

void Worker::takeTool(ITool* tool) {}

void Worker::useTool(ITool* tool) {}
