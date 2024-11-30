#pragma once

#include "IEmployee.hpp"

class Apprentice : public IEmployee {
 public:
  explicit Apprentice(int hourlyValue) : _hourlyValue(hourlyValue) {}
  ~Apprentice() override = default;

  void ExecuteWorkday() override {
    if (_schoolHours == 0) {
      return;
    }
    _hoursWorked += (7 - _timeOff) + (_schoolHours / 2);
  }

  double GetHourlyValue() const override { return _hourlyValue; }

  double GetHoursWorked() const override { return _hoursWorked; }

  void SetSchoolHours(int schoolHours) { _schoolHours = schoolHours; }

  void SetTimeOff(int timeOff) { _timeOff = timeOff; }

 private:
  int _timeOff{};
  int _hourlyValue{};
  int _hoursWorked{};
  int _schoolHours{};
};
