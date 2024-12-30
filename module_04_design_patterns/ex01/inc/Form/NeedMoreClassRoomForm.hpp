#pragma once

#include "IForm.hpp"

class NeedMoreClassRoomForm : public IForm
{
public:
    ~NeedMoreClassRoomForm() override = default;

    void execute() override;
};
