#pragma once

#include "IEmployee.hpp"

class TempWorker : public IEmployee {
 public:
  explicit TempWorker(double hourlyValue) : _hourlyValue(hourlyValue) {}
  ~TempWorker() override = default;

  void ExecuteWorkday() override {
    for (; _hoursToWork; --_hoursToWork) {
      ++_hoursWorked;
    }
  }

  double GetHourlyValue() const override { return _hourlyValue; }

  double GetHoursWorked() const override { return _hoursWorked; }

  void SetHoursToWork(int hoursToWork) { _hoursToWork = hoursToWork; }

 private:
  double _hourlyValue{};
  int _hoursWorked{};
  int _hoursToWork{};
};
