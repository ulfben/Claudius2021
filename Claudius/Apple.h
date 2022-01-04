#pragma once
#include "Color.h"
#include "Renderer.h"
#include "Vector2.h"
#include "RNG.h"
class Apple {  
  Color color{255, 0, 0, 0};
  Vector2 pos{0, 0};
 public:
  Apple() noexcept { respawn();  }
  void render(const Renderer& r) const noexcept { r.render(pos, color); }
  inline Vector2 getPos() const noexcept { return pos;  }
  inline void respawn() noexcept {    
    xoshiro256ss rng(pos.length_squared());    
    const auto col = rng(0, COLUMNS - 1);
    const auto row = rng(0, COLUMNS - 1);
    pos.x = narrow_cast<int>(col) * TILE_SIZE; 
    pos.y = narrow_cast<int>(row) * TILE_SIZE;
  }
};