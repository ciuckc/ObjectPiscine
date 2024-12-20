#pragma once
#include "IPerson.hpp"

class IForm;

class IStaff : public IPerson
{
public:
    virtual ~IStaff() = default;

    virtual void sign(IForm* form) = 0;
};
