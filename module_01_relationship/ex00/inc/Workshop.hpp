#pragma once

#include <stdexcept>
#include <vector>

#include "IWorkshop.hpp"
#include "Worker.hpp"

template <typename RequiredTool>
  requires std::is_base_of_v<Tool, RequiredTool>
class Workshop final : public IWorkshop {
 public:
  Workshop() = default;
  Workshop(const Workshop&) = delete;
  Workshop(Workshop&&) = delete;
  Workshop& operator=(const Workshop&) = delete;
  Workshop& operator=(Workshop&&) = delete;
  ~Workshop() override;

  void subscribe(Worker* worker) override;
  void unsubscribe(Worker* worker) override;
  void executeWorkDay() override;

 private:
  std::vector<Worker*> workers_{};
};

template <typename RequiredTool>
  requires std::is_base_of_v<Tool, RequiredTool>
void Workshop<RequiredTool>::subscribe(Worker* worker) {
  if (std::ranges::find(this->workers_, worker) != this->workers_.end()) {
    std::cerr << "Worker is already subscribed!\n";
    return;
  }
  if (!worker->getTool<RequiredTool>()) {
    throw std::runtime_error("Worker doesn't have this tool!");
  }
  this->workers_.push_back(worker);
}

template <typename RequiredTool>
  requires std::is_base_of_v<Tool, RequiredTool>
void Workshop<RequiredTool>::unsubscribe(Worker* worker) {
  auto iter = std::ranges::find(this->workers_, worker);
  if (iter == this->workers_.end()) {
    std::cerr << "Worker not in workshop\n";
    return;
  }
  this->workers_.erase(iter);
}

template <typename RequiredTool>
  requires std::is_base_of_v<Tool, RequiredTool>
void Workshop<RequiredTool>::executeWorkDay() {
  for (Worker* worker : this->workers_) {
    worker->work<RequiredTool>(this);
  }
}

template <typename RequiredTool>
  requires std::is_base_of_v<Tool, RequiredTool>
Workshop<RequiredTool>::~Workshop() {
  for (auto worker : this->workers_) {
    worker->unsubscribeFromWorkshop(this);
  }
}
