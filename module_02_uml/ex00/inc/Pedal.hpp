#pragma once

#include "LinkablePart.hpp"
class Pedal {
 public:
  void setTarget(LinkablePart* p_part) { this->linkable_part_ = p_part; }
  void use(float p_pression) {
    if (linkable_part_ != nullptr) {
      this->linkable_part_->execute(p_pression);
    }
  }

 private:
  LinkablePart* linkable_part_{};
};
