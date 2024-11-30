#pragma once

#include "IEmployee.hpp"

class ContractEmployee : public IEmployee {
 public:
  explicit ContractEmployee(double hourlyValue) : _hourlyValue(hourlyValue) {}
  ~ContractEmployee() override = default;

  void ExecuteWorkday() override {
    if (_hoursOff == 0) {
      // Just work as usual
      return;
    }
    if (_hoursOff >= 7) {
      _totalHoursOff += 7;
      _hoursOff -= 7;
    } else if (_hoursOff < 7) {
      _totalHoursOff -= _hoursOff;
      _hoursOff = 0;
    }
  }

  double GetHourlyValue() const override { return _hourlyValue; }

  double GetHoursWorked() const override { return 140 - _totalHoursOff; }

  void SetHoursOff(int hoursOff) {
    if (_totalHoursOff + _hoursOff + hoursOff >= 140) {
      return;
    }
    _hoursOff += hoursOff;
  }

 private:
  double _hourlyValue{};
  int _hoursOff{};
  int _totalHoursOff{};
};
