#pragma once

#include "FormType.hpp"
#include "IStaff.hpp"

class IForm;
class ISchoolSpace;

class Secretary : public IStaff
{
public:
    ~Secretary() override = default;

    IForm* createForm(FormType formType);
    void archiveForm();
    void sign(IForm* form) override;
    std::string getName() const override;
    ISchoolSpace* getSchoolSpace() const override;
};
