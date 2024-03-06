#pragma once

#include <iostream>
#include <utility>

struct Statistic {
  Statistic(int level, int exp) : level{level}, exp{exp} { std::cout << "Statistic constructed!\n"; }
  Statistic() { std::cout << "Statistic constructed!\n"; }
  Statistic(const Statistic& rhs) : level{rhs.level}, exp{rhs.exp} {
    std::cout << "Statistic copy constructed!\n";
  }
  Statistic(Statistic&& rhs) noexcept : level{rhs.level}, exp{rhs.exp} {
    rhs.level = {};
    rhs.exp = {};
    std::cout << "Statistic move constructed!\n";
  }
  Statistic& operator=(Statistic&& rhs) noexcept {
    if (this == &rhs) {
      return *this;
    }
    this->level = std::exchange(rhs.level, {});
    this->exp = std::exchange(rhs.exp, {});
    std::cout << "Statistic move assigned!\n";
    return *this;
  }
  Statistic& operator=(const Statistic& rhs) {
    if (this == &rhs) {
      return *this;
    }
    this->level = rhs.level;
    this->exp = rhs.exp;
    std::cout << "Statistic copy assigned!\n";
    return *this;
  }
  ~Statistic() { std::cout << "Statistic deconstructed!\n"; }

  int level{};
  int exp{};
};

inline std::ostream& operator<<(std::ostream& out, const Statistic& obj) {
  out << "[level: " << obj.level << ", exp: " << obj.exp << "]";
  return out;
}
