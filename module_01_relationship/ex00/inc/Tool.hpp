#pragma once

#include "Worker.hpp"

class Tool {
 public:
  Tool() = default;
  Tool(const Tool&) = delete;
  Tool& operator=(const Tool&) = delete;
  Tool(Tool&&) = default;
  Tool& operator=(Tool&&) = default;
  virtual ~Tool() = default;

  virtual void use() = 0;
  virtual void takeFromCurrentWorker();
  virtual void assignToWorker(Worker* new_worker);

 protected:
  Worker* worker_{};
  int num_of_uses_{};
};
