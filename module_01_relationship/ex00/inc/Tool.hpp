#pragma once

class Worker;

class Tool {
 public:
  Tool() = default;
  Tool(const Tool&) = delete;
  Tool& operator=(const Tool&) = delete;
  Tool(Tool&&) = default;
  Tool& operator=(Tool&&) = default;
  virtual ~Tool() = default;

  virtual void use() = 0;
  virtual void assignToWorker(Worker*);
  virtual void takeFromCurrentWorker();

 protected:
  Worker* worker_;
};
