#pragma once

#include <vector>

#include "ISchoolSpace.hpp"

class IPerson;

class HeadmasterOffice : public ISchoolSpace {
 public:
  ~HeadmasterOffice() override;

  bool canEnter(IPerson*) override;
  void enter(IPerson*) override;
  void exit(IPerson*) override;
  std::vector<IPerson*> getOccupants() const override;
  long long getId() const override;
};
