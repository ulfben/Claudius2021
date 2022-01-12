#pragma once
#include <vector>

#include "Color.h"
#include "KeyCode.h"
#include "Rectangle.h"
#include "Renderer.h"
#include "Coord.h"

class Player {
  std::vector<Coord> body_segments{1, Coord{STAGE_CENTER_X, STAGE_CENTER_Y}};  
  Coord heading = STILL;
  Color color{0, 255, 0, 0};

  Coord& head() noexcept { return *body_segments.begin(); }
  const Coord& head() const noexcept { return *body_segments.begin(); }
  bool hasTrailingSegments() const noexcept { return length() > 1; }
  bool isInside(Rectangle bounds) const noexcept;  
 
public:
  int score = 0;
  void onKeyDown(KeyCode key) noexcept;  
  void render(const Renderer& renderer) const noexcept;
  void update() noexcept;
  void respawn() noexcept;
  bool isSelfColliding() const noexcept;
  bool isColliding(Coord pos) const noexcept;  
  bool isOutsideOf(Rectangle bounds) const noexcept;
  void grow() noexcept;
  Coord getPos() const noexcept { return head(); }
  size_t length() const noexcept { return body_segments.size(); }
};