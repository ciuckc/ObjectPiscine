#pragma once

#include <algorithm>
#include <ostream>
#include <string>
#include <type_traits>
#include <vector>

class Worker;

#include "ITool.hpp"
#include "IWorkshop.hpp"
#include "Position.hpp"
#include "Statistic.hpp"

class IWorkshop;

class Worker {
 public:
  explicit Worker(std::string name);
  Worker();
  Worker(const Worker& rhs) = delete;
  Worker(Worker&& rhs) noexcept;
  Worker& operator=(const Worker& rhs) = delete;
  Worker& operator=(Worker&& rhs) noexcept;
  ~Worker();

  void setName(const std::string& name) { this->name_ = name; }
  [[nodiscard]] const std::string& getName() const { return this->name_; }

  void setPosition(const Position& pos) { this->pos_ = pos; }
  [[nodiscard]] const Position& getPosition() const { return pos_; }

  void setStatistic(const Statistic& stats) { this->stats_ = stats; }
  [[nodiscard]] const Statistic& getStatistic() const { return stats_; }

  void giveTool(ITool* tool);
  void takeTool(ITool* tool);

  void useTool(ITool* tool);

  template <typename T>
    requires std::is_base_of_v<ITool, T>
  [[nodiscard]] ITool* getTool() const;

  void subscribeToWorkshop(IWorkshop* workshop);
  void unsubscribeFromWorkshop(IWorkshop* workshop);

  template <typename Tool>
  void work(IWorkshop* workshop);

 private:
  std::string name_{};
  std::vector<IWorkshop*> workshops_{};
  Statistic stats_{};
  Position pos_{};
};

std::ostream& operator<<(std::ostream& out, const Worker& obj);

template <typename T>
  requires std::is_base_of_v<ITool, T>
ITool* Worker::getTool() const {
  return nullptr;
}

template <typename Tool>
void Worker::work(IWorkshop* workshop) {
  if (const auto iter = std::ranges::find(this->workshops_, workshop); iter == this->workshops_.end()) {
    std::cerr << "Worker, " << this->name_ << ", is not subscribed/allowed to this workshop!\n";
    return;
  }
  auto tool = this->getTool<Tool>();
  if (!tool) {
    std::cerr << "Worker, " << this->name_ << ", doesn't have this tool!\n";
    return;
  }
  std::cout << "Worker, " << this->name_ << ", started to work!\n";
}
