#pragma once

class Shape {
 public:
  virtual ~Shape() = default;
  virtual double GetArea() const = 0;
};
