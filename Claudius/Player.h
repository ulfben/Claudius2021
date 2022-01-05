#pragma once
#include <vector>

#include "Color.h"
#include "KeyCode.h"
#include "Rectangle.h"
#include "Renderer.h"
#include "Vector2.h"

class Player {
  std::vector<Vector2> body_segments{1, Vector2{STAGE_CENTER_X, STAGE_CENTER_Y}};  
  Vector2 heading = STILL;
  Color color{0, 255, 0, 0};

  Vector2& head() noexcept { return *body_segments.begin(); }
  const Vector2& head() const noexcept { return *body_segments.begin(); }
  bool hasTrailingSegments() const noexcept { return length() > 1; }

 public:
  int score = 0;
  void onKeyDown(KeyCode key) noexcept;
  void render(const Renderer& renderer) const noexcept;

  void update() noexcept;
  void respawn() noexcept;
  bool isSelfColliding() const noexcept;
  bool isColliding(Vector2 pos) const noexcept;
  bool isInside(Rectangle bounds) const noexcept;
  void grow() noexcept;
  Vector2 getPos() const noexcept { return head(); }
  size_t length() const noexcept { return body_segments.size(); }
};