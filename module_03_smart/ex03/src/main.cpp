#include "Apprentice.hpp"
#include "ContractEmployee.hpp"
#include "EmployeeManager.hpp"
#include "IEmployee.hpp"
#include "TempWorker.hpp"

int main() {
  EmployeeManager director;

  Apprentice* apprentice = new Apprentice{18};
  ContractEmployee* contractEmployee = new ContractEmployee{25};
  TempWorker* tempWorker = new TempWorker{21};

  director.AddEmployee(apprentice);
  director.AddEmployee(contractEmployee);
  director.AddEmployee(tempWorker);

  apprentice->SetSchoolHours(4);
  apprentice->SetTimeOff(1);

  contractEmployee->SetHoursOff(2);

  tempWorker->SetHoursToWork(6);

  director.ExecuteWorkday();
  // Time passes people work and now it s time to pay up
  director.CalculatePayroll();
}