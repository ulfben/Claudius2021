#pragma once
#include <cmath>
#include "Rectangle.h"
 
struct Coord {
  int x = 0;
  int y = 0;

  void operator+=(Coord rhs) noexcept {
    //mathematically speaking, it makes no sense to add coordinates together. But it sure is convenient. :P
    x += rhs.x;
    y += rhs.y;
  }
  bool operator==(Coord rhs) const noexcept {
    return x == rhs.x && y == rhs.y;
  }
};

inline constexpr bool isBetween(auto in, auto min, auto max) noexcept {
  return min <= in && max >= in;
}
inline constexpr bool isInside(Coord pos, Rectangle bounds) noexcept {
  return isBetween(pos.x, bounds.left(), bounds.right()) &&
         isBetween(pos.y, bounds.top(), bounds.bottom());
}

//to help clarify code where Coord is used as a direction
using Vector2 = Coord;