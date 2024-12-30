#pragma once

#include <vector>

#include "ISchoolSpace.hpp"

class IForm;
class IPerson;

class SecretarialOffice : public ISchoolSpace {
 public:
  ~SecretarialOffice() override = default;

  bool canEnter(IPerson*) override;
  void enter(IPerson*) override;
  void exit(IPerson*) override;
  std::vector<IPerson*> getOccupants() const override;
  long long getId() const override;

 private:
  std::vector<IForm*> _archivedForms;
};
