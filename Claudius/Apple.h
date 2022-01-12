#pragma once
#include "Color.h"
#include "Renderer.h"
#include "Coord.h"
#include "RNG.h"
class Apple {  
  static constexpr Color color{255, 0, 0, ALPHA_OPAQUE};
  Coord pos{0, 0};
 public:  
  void render(const Renderer& r) const noexcept { r.render(pos, color); }
  inline Coord getPos() const noexcept { return pos;  }
  inline void respawn(xoshiro256ss& rng) noexcept {        
    const auto col = rng(0, COLUMNS - 1);
    const auto row = rng(0, COLUMNS - 1);
    pos.x = narrow_cast<int>(col) * TILE_SIZE; 
    pos.y = narrow_cast<int>(row) * TILE_SIZE;
  }
};