#pragma once

#include "Shape.hpp"

class Triangle : public Shape {
 public:
  Triangle(double base, double height) : _base(base), _height(height) {}

  double GetArea() const override { return _base * 0.5 * _height; }

 private:
  double _base{};
  double _height{};
};
