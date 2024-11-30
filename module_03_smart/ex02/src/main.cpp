#include <cassert>
#include <iostream>
#include <vector>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Triangle.hpp"

double CalculateTotalArea(std::vector<Shape*> shapes) {
  double total_area = 0.0;
  for (auto shape : shapes) {
    total_area += shape->GetArea();
  }
  return total_area;
}

int main() {
  Shape* triangle = new Triangle(10.0, 5.0);
  Shape* circle = new Circle(4.0);
  Shape* rectangle = new Rectangle(2.0, 4.0);

  std::vector<Shape*> shapes{triangle, circle, rectangle};

  assert(CalculateTotalArea(shapes) >= (25.0 + 48.0 + 8.0));
  std::cout << "Total area: " << CalculateTotalArea(shapes) << "\n";
}
