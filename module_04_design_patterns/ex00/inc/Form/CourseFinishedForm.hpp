#pragma once
#include "IForm.hpp"

class CourseFinishedForm : public IForm
{
public:
    ~CourseFinishedForm() override = default;

    void execute() override;
};
