#include "Vector2.h"

Vector2::Vector2(float x, float y) : x_(x), y_(y) {}

float Vector2::getX() const {
  return this->x_;
}

float Vector2::getY() const {
  return this->y_;
}

void Vector2::setX(float x) {
  this->x_ = x;
}

void Vector2::setY(float y) {
  this->y_ = y;
}

bool Vector2::operator<(const Vector2& rhs) const {
  return (this->y_ < rhs.y_) || (this->y_ == rhs.y_ && this->x_ < rhs.x_);
}

bool Vector2::operator>(const Vector2& rhs) const {
  return !this->operator==(rhs) && !this->operator<(rhs);
}

std::ostream& operator<<(std::ostream& os, const Vector2& object) {
  os << '[' << "x: " << object.getX() << ", " << object.getY() << ']';
  return os;
}
