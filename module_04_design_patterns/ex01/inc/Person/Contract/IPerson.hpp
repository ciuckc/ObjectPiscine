#pragma once

#include <string>

class ISchoolSpace;

class IPerson
{
public:
    virtual ~IPerson() = default;

    virtual std::string getName() const = 0;
    virtual ISchoolSpace* getSchoolSpace() const = 0;
};
