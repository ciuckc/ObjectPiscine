#pragma once

class LinkablePart {
  public:
    virtual void execute(float pressure) = 0;
    virtual ~LinkablePart();
};