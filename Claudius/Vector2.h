#pragma once

struct Vector2 {
  float x = 0.0f;
  float y = 0.0f;
  Vector2() = default;
  constexpr Vector2(const float x, const float y) noexcept : x(x), y(y) {}

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
  Vector2 operator/(const Vector2& rhs) const noexcept;
  Vector2 operator*(const float rhs) const noexcept;
  Vector2 operator/(const float rhs) const noexcept;

  Vector2 perpendicular() const noexcept;
  Vector2 unit() const noexcept;

  float length() const noexcept;
  float length_squared() const noexcept;
  float dot(const Vector2& rhs) const noexcept;
  float cross(const Vector2& rhs) const noexcept;
  void normalize() noexcept;
};

inline constexpr bool isBetween(float in, int min, int max) noexcept {
  return min <= in && max >= in;
}