#pragma once

#include "ISchoolSpace.hpp"

class StaffRestRoom : public ISchoolSpace
{
public:
    ~StaffRestRoom() override = default;

    bool canEnter(IPerson*) override;
    void enter(IPerson*) override;
    void exit(IPerson*) override;
    std::vector<IPerson*> getOccupants() const override;
    long long getId() const override;
};
