#pragma once

#include <numbers>

#include "Shape.hpp"

class Circle : public Shape {
 public:
  Circle(double radius) : _radius(radius) {}

  double GetArea() const override { return _radius * _radius * std::numbers::pi; }

 private:
  double _radius{};
};
