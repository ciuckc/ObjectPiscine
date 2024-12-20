#pragma once

#include <vector>

class IPerson;

class ISchoolSpace
{
public:
    virtual ~ISchoolSpace() = default;

    virtual bool canEnter(IPerson* person) = 0;
    virtual void enter(IPerson* person) = 0;
    virtual void exit(IPerson* person) = 0;
    virtual std::vector<IPerson*> getOccupants() const = 0;
    virtual long long getId() const = 0;
};
