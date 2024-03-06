#pragma once

#include <ostream>

class Vector2 {
 public:
  Vector2(float x, float y);
  Vector2() = default;
  Vector2(const Vector2& rhs) = default;
  Vector2(Vector2&& rhs) = default;
  Vector2& operator=(const Vector2& rhs) = default;
  Vector2& operator=(Vector2&& rhs) = default;
  ~Vector2() = default;

  void setX(float x);
  void setY(float y);

  [[nodiscard]] float getX() const;
  [[nodiscard]] float getY() const;

  auto operator<=>(const Vector2& rhs) const = default;
  bool operator<(const Vector2& rhs) const;
  bool operator>(const Vector2& rhs) const;

 private:
  float x_{0.0f};
  float y_{0.0f};
};

std::ostream& operator<<(std::ostream& os, const Vector2& rhs);
