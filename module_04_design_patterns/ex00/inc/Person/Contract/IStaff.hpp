#pragma once
#include "IPerson.hpp"

class IStaff : public IPerson
{
public:
    virtual ~IStaff() = default;

    virtual void sign(IForm* p_form) = 0;
};
