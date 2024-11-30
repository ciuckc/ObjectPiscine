#pragma once

#include "IForm.hpp"

class NeedCourseCreationForm : public IForm
{
public:
    ~NeedCourseCreationForm() override = default;

    void execute() override;
};
