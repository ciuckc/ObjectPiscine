#pragma once

#include <string>
#include <vector>

#include "IStaff.hpp"

class IForm;

class Headmaster : public IStaff
{
public:
    ~Headmaster() override = default;

    void receiveForm(IForm* p_form);
    void sign(IForm* p_form) override;
    std::string getName() const override;
    ISchoolSpace* getSchoolSpace() const override;

private:
    std::vector<IForm*> _formToValidate{};
};
