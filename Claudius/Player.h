#pragma once
#include <vector>

#include "Color.h"
#include "KeyCode.h"
#include "Rectangle.h"
#include "Renderer.h"
#include "Coord.h"

class Player {
  static constexpr Color color{0, 255, 0, 0};
  std::vector<Coord> body{1, Coord{STAGE_CENTER_X, STAGE_CENTER_Y}};  
  Coord heading = STILL; 

  Coord& head() noexcept { return *body.begin(); }
  const Coord& head() const noexcept { return *body.begin(); }
  Coord position() const noexcept { return body.front(); }
  bool hasTail() const noexcept { return body.size() > 1; }  
  
public:  
  void onKeyDown(KeyCode key) noexcept;    
  void update() noexcept;
  void render(const Renderer& renderer) const noexcept;
  void respawn() noexcept;
  void grow() noexcept;  
  bool isSelfColliding() const noexcept;
  bool isCollidingWith(Coord pos) const noexcept;  
  bool isOutsideOf(Rectangle bounds) const noexcept;  
};