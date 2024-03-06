#pragma once

#include "Worker.hpp"

class IWorkshop {
public:
  virtual ~IWorkshop() = default;

  virtual void subscribe(Worker*) = 0;
  virtual void unsubscribe(Worker*) = 0;
  virtual void executeWorkDay() = 0;
};
