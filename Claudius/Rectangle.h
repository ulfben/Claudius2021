#pragma once
struct Rectangle {
  unsigned x = 0;
  unsigned y = 0;
  unsigned w = 0;
  unsigned h = 0;
  inline int left() const noexcept { return x; }
  inline int top() const noexcept { return y; }
  inline int right() const noexcept { return x + w; }
  inline int bottom() const noexcept { return y + h; }  
};