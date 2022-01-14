#pragma once
#include "Color.h"
#include "Renderer.h"
#include "Coord.h"
#include "RNG.h"
class Apple {    
  Coord pos{0, 0};
 public:  
  void render(const Renderer& r) const noexcept { r.render(pos, RED); }
  Coord position() const noexcept { return pos;  }
  void respawn(RNG& rng) noexcept {        
    const auto col = rng(0, COLUMNS - 1);
    const auto row = rng(0, COLUMNS - 1);
    pos.x = narrow_cast<int>(col) * TILE_SIZE; 
    pos.y = narrow_cast<int>(row) * TILE_SIZE;
  }
};