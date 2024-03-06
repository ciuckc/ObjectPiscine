#include "Graph.h"

#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <stdexcept>

#include "Vector2.h"

Graph::Graph(const Vector2& size) : size_(size) {}

Graph::Graph(float width, float length) : size_(width, length) {}

void Graph::addPoint(const Vector2& point) {
  if (point.getX() < 0 || point.getX() >= this->size_.getX()) {
    throw std::out_of_range{"Out of range on x."};
  }
  if (point.getY() < 0 || point.getY() >= this->size_.getY()) {
    throw std::out_of_range{"Out of range on y."};
  }

  auto iter = points_.insert(point);
  if (!iter.second) {
    std::cerr << "Value " << point << " already exists." << std::endl;
    throw std::invalid_argument{"Point is already in set."};
  }
}

const std::set<Vector2>& Graph::getPoints() const& {
  return this->points_;
}

Vector2 Graph::size() const {
  return this->size_;
}

std::ostream& operator<<(std::ostream& os, const Graph& obj) {
  os << '\n';

  auto width = obj.size().getX();
  auto length = obj.size().getY();
  --length;
  auto num_len = 1 + static_cast<std::size_t>(std::log10(length));
  const auto& points = obj.getPoints();
  for (auto i = length;; --i) {
    std::cout << "&>" << std::right << std::setw(num_len + 1) << i;
    for (auto j = 0; j < width; ++j) {
      if (points.contains(Vector2(j, i))) {
        std::cout << std::right << std::setw(num_len + 1) << 'X';
      } else {
        std::cout << std::right << std::setw(num_len + 1) << '.';
      }
    }
    std::cout << '\n';
    if (i == 0) {
      break;
    }
  }
  std::cout << "&>" << std::right << std::setw(num_len + 1) << ' ';
  for (auto j = 0; j < width; ++j) {
    std::cout << std::right << std::setw(num_len + 1) << j;
  }
  os << '\n';
  return os;
}
