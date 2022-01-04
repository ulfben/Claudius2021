#pragma once
struct Rectangle {
  unsigned x{};
  unsigned y{};
  unsigned w{};
  unsigned h{};
  inline int left() const noexcept { return x; }
  inline int top() const noexcept { return y; }
  inline int right() const noexcept { return x + w; }
  inline int bottom() const noexcept { return y + h; }  
};