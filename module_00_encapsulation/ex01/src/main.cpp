#include <iostream>

#include "Graph.h"
#include "Vector2.h"

int main() {
  Graph graph(10, 15);
  graph.addPoint(Vector2{0, 0});
  graph.addPoint(Vector2{1, 1});
  graph.addPoint(Vector2{1, 14});
  std::cout << graph;
}
