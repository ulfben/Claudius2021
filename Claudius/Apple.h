#pragma once
#include "Color.h"
#include "Renderer.h"
#include "Vector2.h"

class Apple {  
  Color color{0, 255, 0, 0};
  Vector2 pos{100.0f, 200.0f};
 public:
  void render(const Renderer& r) const noexcept { r.render(pos, color); }
  inline Vector2 getPos() const noexcept { return pos;  }
  inline void respawnWithin(Rectangle bounds) noexcept {
    pos.x = static_cast<float>((rand() % bounds.w) + bounds.x);
    pos.y = static_cast<float>((rand() % bounds.h) + bounds.y);
  }
};