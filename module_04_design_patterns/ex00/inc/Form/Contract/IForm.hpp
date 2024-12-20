#pragma once

class IForm
{
public:
    virtual ~IForm() = default;

    virtual void execute() = 0;
};
