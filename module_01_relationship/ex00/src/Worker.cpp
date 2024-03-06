#include "Worker.hpp"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"

Worker::Worker(std::string name) : name_{std::move(name)} {
  std::cout << "Worker " << this->name_ << " constructed!\n";
}

Worker::Worker() {
  std::cout << "Worker default constructed!\n";
}

Worker::Worker(Worker&& rhs) noexcept
    : name_{std::move(rhs.name_)},
      tools_{std::move(rhs.tools_)},
      stats_{std::move(rhs.stats_)},
      pos_{std::move(rhs.pos_)} {
  rhs.pos_ = {};
  rhs.stats_ = {};
  std::cout << "Worker move constructed!\n";
}

Worker& Worker::operator=(Worker&& rhs) noexcept {
  if (this == &rhs) {
    return *this;
  }
  this->name_ = std::move(rhs.name_);
  this->tools_ = std::exchange(rhs.tools_, {});
  this->pos_ = std::exchange(rhs.pos_, {});
  this->stats_ = std::exchange(rhs.stats_, {});
  std::cout << "Worker move assigned!\n";
  return *this;
}

Worker::~Worker() {
  for (Tool* tool : this->tools_) {
    if (tool != nullptr) {
      tool->takeFromCurrentWorker();
    }
  }
  for (const auto workshop : this->workshops_) {
    workshop->unsubscribe(this);
  }
}

// this is so messed up, such a high coupling
void Worker::giveTool(Tool* tool) {
  if (tool == nullptr) {
    return;
  }
  const auto iter = std::ranges::find(this->tools_, tool);
  if (iter != this->tools_.end() && *iter == tool) {
    return;
  }
  this->tools_.push_back(tool);
  tool->assignToWorker(this);
  std::cout << "Worker " << this->name_ << " has a new tool!\n";
}

void Worker::takeTool(Tool* tool) {
  if (tool == nullptr) {
    return;
  }
  const auto iter = std::ranges::find(this->tools_, tool);
  if (iter == this->tools_.end()) {
    return;
  }
  Tool* curr_tool_ptr = *iter;
  this->tools_.erase(iter);
  curr_tool_ptr->takeFromCurrentWorker();
  std::cout << "Worker " << this->name_ << " doesn't have a tool anymore!\n";
}

void Worker::useTool(const Tool* tool) {
  if (tool == nullptr) {
    std::cout << "Worker " << this->name_ << " can't use a tool that doesn't exist!\n";
    return;
  }
  auto iter = std::find(this->tools_.begin(), this->tools_.end(), tool);
  if (iter == this->tools_.end()) {
    std::cout << "Worker " << this->name_ << " doesn't have this tool!\n";
    return;
  }
  (*iter)->use();
  std::cout << "Worker " << this->name_ << " is using the tool!\n";
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
  if ( iter == this->workshops_.end()) {
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
