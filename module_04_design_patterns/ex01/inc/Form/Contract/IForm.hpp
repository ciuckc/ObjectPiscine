#pragma once

class IForm
{
public:
    virtual void execute() = 0;

    virtual ~IForm() = default;
};
