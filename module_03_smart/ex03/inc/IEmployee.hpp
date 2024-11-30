#pragma once

class IEmployee {
 public:
  virtual void ExecuteWorkday() = 0;
  virtual double GetHourlyValue() const = 0;
  virtual double GetHoursWorked() const = 0;
  virtual ~IEmployee() = default;
};
