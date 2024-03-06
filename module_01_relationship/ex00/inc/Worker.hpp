#pragma once

#include <algorithm>
#include <ostream>
#include <string>
#include <type_traits>
#include <vector>

class Worker;

#include "IWorkshop.hpp"
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"

class Tool;

class IWorkshop;

template <typename RequiredTool>
  requires std::is_base_of_v<Tool, RequiredTool>
class Workshop;

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

  template <typename T>
    requires std::is_base_of_v<Tool, T>
  [[nodiscard]] Tool* getTool() const;

  void giveTool(Tool* tool);
  void takeTool(Tool* tool);

  void useTool(const Tool* tool);

  void subscribeToWorkshop(IWorkshop* workshop);
  void unsubscribeFromWorkshop(IWorkshop* workshop);

  template <typename Tool>
  void work(IWorkshop* workshop);

 private:
  std::string name_{};
  std::vector<IWorkshop*> workshops_{};
  std::vector<Tool*> tools_{};
  Statistic stats_{};
  Position pos_{};
};

std::ostream& operator<<(std::ostream& out, const Worker& obj);

template <typename T>
  requires std::is_base_of_v<Tool, T>
Tool* Worker::getTool() const {
  for (auto* tool : this->tools_) {
    if (dynamic_cast<T*>(tool) != nullptr) {
      return tool;
    }
  }
  return nullptr;
}
template<typename Tool>
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
  this->useTool(tool);
}
