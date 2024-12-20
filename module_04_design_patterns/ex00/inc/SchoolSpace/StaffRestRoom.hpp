#pragma once

#include <vector>

#include "ISchoolSpace.hpp"

class IPerson;

class StaffRestRoom : public ISchoolSpace
{
public:
    ~StaffRestRoom() override = default;

    bool canEnter(IPerson* person) override;
    void enter(IPerson* person) override;
    void exit(IPerson* person) override;
    std::vector<IPerson*> getOccupants() const override;
    long long getId() const override;
};
