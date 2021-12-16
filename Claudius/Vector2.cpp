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

Vector2 Vector2::operator/(const Vector2& rhs) const noexcept {
  return Vector2(x / rhs.x, y / rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const noexcept {
  return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const noexcept {
  return Vector2(x / rhs, y / rhs);
}

Vector2 Vector2::perpendicular() const noexcept {
  return Vector2(-y, x);  // 90 degrees to the right
}

Vector2 Vector2::unit() const noexcept {
  Vector2 result(*this);
  result.normalize();
  return result;
}

float Vector2::length() const noexcept { return sqrtf(x * x + y * y); }

float Vector2::length_squared() const noexcept { return x * x + y * y; }

float Vector2::dot(const Vector2& rhs) const noexcept {
  return x * rhs.x + y * rhs.y;
}

float Vector2::cross(const Vector2& rhs) const noexcept  {
  return x * rhs.y - y * rhs.x;
}

void Vector2::normalize() noexcept {
  const float len = length();
  if (len <= 0.0f) return;
  x /= len;
  y /= len;
}
