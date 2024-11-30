#pragma once

#include <stdexcept>
#include <vector>

#include "IWorkshop.hpp"
#include "Worker.hpp"

template <typename RequiredTool>
  requires std::is_base_of_v<ITool, RequiredTool>
class Workshop final : public IWorkshop {
 public:
  Workshop() = default;
  Workshop(const Workshop&) = delete;
  Workshop(Workshop&&) = delete;
  Workshop& operator=(const Workshop&) = delete;
  Workshop& operator=(Workshop&&) = delete;

  ~Workshop() override {
    for (auto worker : this->workers_) {
      worker->unsubscribeFromWorkshop(this);
    }
  }

  void subscribe(Worker* worker) override {
    if (std::ranges::find(this->workers_, worker) != this->workers_.end()) {
      std::cerr << "Worker is already subscribed!\n";
      return;
    }
    if (!worker->getTool<RequiredTool>()) {
      throw std::runtime_error("Worker doesn't have this tool!");
    }
    this->workers_.push_back(worker);
  }

  void unsubscribe(Worker* worker) override {
    auto iter = std::ranges::find(this->workers_, worker);
    if (iter == this->workers_.end()) {
      std::cerr << "Worker not in workshop\n";
      return;
    }
    this->workers_.erase(iter);
  }

  void executeWorkDay() override {
    for (Worker* worker : this->workers_) {
      worker->work<RequiredTool>(this);
    }
  }

 private:
  std::vector<Worker*> workers_{};
};
