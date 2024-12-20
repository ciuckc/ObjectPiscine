#pragma once

#include <vector>

#include "ISchoolSpace.hpp"

class IForm;
class IPerson;

class SecretarialOffice : public ISchoolSpace
{
public:
 ~SecretarialOffice() override = default;

 bool canEnter(IPerson* person) override;
 void enter(IPerson* person) override;
 void exit(IPerson* person) override;
 std::vector<IPerson*> getOccupants() const override;
 long long getId() const override;

private:
 std::vector<IForm*> _archivedForms;
};
