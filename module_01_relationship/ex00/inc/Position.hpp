#pragma once

#include <iostream>
#include <ostream>
#include <utility>

struct Position {
 public:
  Position(int x, int y, int z) : x{x}, y{y}, z{z} { std::cout << "Position constructed!\n"; }
  Position() { std::cout << "Position constructed!\n"; }
  Position(const Position& rhs) : x{rhs.x}, y{rhs.y}, z{rhs.z} {
    std::cout << "Position copy constructed!\n";
  }
  Position(Position&& rhs) noexcept : x{rhs.x}, y{rhs.y}, z{rhs.z} {
    rhs.x = 0;
    rhs.y = 0;
    rhs.z = 0;
    std::cout << "Position move constructed!\n";
  };
  Position& operator=(const Position& rhs) {
    if (this == &rhs) {
      return *this;
    }
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    std::cout << "Position copy assigned!\n";
    return *this;
  }
  Position& operator=(Position&& rhs) noexcept {
    if (this == &rhs) {
      return *this;
    }
    this->x = std::exchange(rhs.x, {});
    this->y = std::exchange(rhs.y, {});
    this->z = std::exchange(rhs.z, {});
    std::cout << "Position move assigned!\n";
    return *this;
  }
  ~Position() { std::cout << "Position deconstructed\n"; }

  int x{};
  int y{};
  int z{};
};

inline std::ostream& operator<<(std::ostream& out, const Position& obj) {
  out << "[x: " << obj.x << ", y: " << obj.y << ", z: " << obj.z << "]";
  return out;
}
