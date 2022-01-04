#include "Vector2.h"

#include <cmath>

Vector2 Vector2::operator+(const Vector2& rhs) const noexcept {
  return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const noexcept {
  return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const Vector2& rhs) const noexcept {
  return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator*(const int rhs) const noexcept {
  return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::perpendicular() const noexcept {
  return Vector2(-y, x);  // 90 degrees to the right
}

float Vector2::length() const noexcept { return sqrtf(length_squared()); }

float Vector2::length_squared() const noexcept {
  return static_cast<float>(x * x + y * y);
}

float Vector2::dot(const Vector2& rhs) const noexcept {
  return static_cast<float>(x * rhs.x + y * rhs.y);
}

float Vector2::cross(const Vector2& rhs) const noexcept {
  return static_cast<float>(x * rhs.y - y * rhs.x);
} 