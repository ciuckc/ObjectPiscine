#pragma once

class ITool
{
public:
    ITool() = default;
    ITool(const ITool&) = delete;
    ITool& operator=(const ITool&) = delete;
    ITool(ITool&&) = default;
    ITool& operator=(ITool&&) = default;
    virtual ~ITool() = default;

    virtual void use() = 0;
};
