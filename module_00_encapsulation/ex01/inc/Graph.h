#pragma once

#include <ostream>
#include <set>

#include "Vector2.h"

class Graph {
 public:
  Graph(const Vector2& size);
  Graph(float width, float length);
  Graph() = default;
  Graph(Graph&&) = default;
  Graph(const Graph&) = default;
  Graph& operator=(const Graph&) = default;
  Graph& operator=(Graph&&) = default;
  ~Graph() = default;

  void addPoint(const Vector2& point);
  const std::set<Vector2>& getPoints() const&;
  Vector2 size() const;

 private:
  std::set<Vector2> points_{};
  Vector2 size_{};
};

std::ostream& operator<<(std::ostream& os, const Graph& obj);
