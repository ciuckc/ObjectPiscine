#pragma once

#include <string>
#include <vector>

#include "IStaff.hpp"

class IForm;

class Headmaster : public IStaff
{
public:
    ~Headmaster() override = default;

    void receiveForm(IForm* form);
    void sign(IForm* form) override;
    std::string getName() const override;
    ISchoolSpace* getSchoolSpace() const override;

private:
    std::vector<IForm*> _formToValidate{};
};
