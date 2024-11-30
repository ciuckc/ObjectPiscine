#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
 public:
  Rectangle(double width, double height) : _width(width), _height(height) {}

  double GetArea() const override { return _width * _height; }

 private:
  double _width{};
  double _height{};
};
