#pragma once
#include "FormType.hpp"
#include "IForm.hpp"
#include "IStaff.hpp"

class Secretary : public IStaff
{
public:
    ~Secretary() override = default;

    IForm* createForm(FormType p_formType);
    void archiveForm();
    void sign(IForm* p_form) override;
    std::string getName() const override;
    ISchoolSpace* getSchoolSpace() const override;
};
