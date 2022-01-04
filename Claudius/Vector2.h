#pragma once
#include "Rectangle.h"
struct Vector2 {
  int x = 0;
  int y = 0;
  Vector2() = default;
  constexpr Vector2(const int x, const int y) noexcept : x(x), y(y) {}

  void operator+=(const Vector2& rhs) noexcept {
    x += rhs.x;
    y += rhs.y;
  }
  bool operator==(const Vector2& rhs) const noexcept {
    return x == rhs.x && y == rhs.y;
  }
  Vector2 operator+(const Vector2& rhs) const noexcept;
  Vector2 operator-(const Vector2& rhs) const noexcept;
  Vector2 operator*(const Vector2& rhs) const noexcept;
  Vector2 operator*(const int rhs) const noexcept;
  Vector2 perpendicular() const noexcept;
  float length() const noexcept;
  float length_squared() const noexcept;
  float dot(const Vector2& rhs) const noexcept;
  float cross(const Vector2& rhs) const noexcept;
};

inline constexpr bool isBetween(auto in, auto min, auto max) noexcept {
  return min <= in && max >= in;
}
inline constexpr bool isInside(Vector2 pos, Rectangle bounds) noexcept {
  return isBetween(pos.x, bounds.left(), bounds.right()) &&
         isBetween(pos.y, bounds.top(), bounds.bottom());
}