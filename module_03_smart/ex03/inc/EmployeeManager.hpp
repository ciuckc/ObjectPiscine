#pragma once

#include <algorithm>
#include <vector>
#include <iostream>

#include "IEmployee.hpp"

class EmployeeManager {
 public:
  /**
   * Adds an IEmployee object to the list of employees if it is not already present.
   *
   * @param employee Pointer to the IEmployee object to be added. If the pointer is null
   *                 or the employee is already in the list, the function returns
   *                 without making any changes.
   */
  void AddEmployee(IEmployee *employee) {
    if (employee == nullptr) {
      return;
    }
    auto it = std::find(_employees.begin(), _employees.end(), employee);
    if (it != _employees.end()) {
      return;
    }
    _employees.push_back(employee);
  }

  /**
   * Removes an IEmployee object from the list of employees if it is present.
   *
   * @param employee Pointer to the IEmployee object to be removed. If the pointer is null
   *                 or the employee is not found in the list, the function returns
   *                 without making any changes.
   */
  void RemoveEmployee(IEmployee *employee) {
    if (employee == nullptr) {
      return;
    }
    auto it = std::find(_employees.begin(), _employees.end(), employee);
    if (it != _employees.end()) {
      _employees.erase(it);
    }
  }

  void ExecuteWorkday() {
    for (auto employee: _employees) {
      if (employee != nullptr) {
        employee->ExecuteWorkday();
      }
    }
  }

  void CalculatePayroll() {
    for (auto employee: _employees) {
      if (employee != nullptr) {
        double hourlyValue = employee->GetHourlyValue();
        double hoursWorked = employee->GetHoursWorked();
        double payroll = hourlyValue * hoursWorked;
        std::cout << "Paid employee: " << payroll << " euros.\n";
      }
    }
  }

 private:
  std::vector<IEmployee *> _employees{};
};
