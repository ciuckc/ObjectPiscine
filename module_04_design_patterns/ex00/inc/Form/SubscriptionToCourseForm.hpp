#pragma once

#include "IForm.hpp"

class SubscriptionToCourseForm : public IForm
{
public:
    ~SubscriptionToCourseForm() override = default;

    void execute() override;
};
