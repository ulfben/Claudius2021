#pragma once
#include <array>

#include "Color.h"
#include "KeyCode.h"
#include "Rectangle.h"
#include "Renderer.h"
#include "Vector2.h"
static constexpr size_t player_size = 50;
static constexpr float movement_speed = 10.0f;
static constexpr float starting_x = 300.0f;
static constexpr float starting_y = 300.0f;
static constexpr Vector2 LEFT(-TILE_SIZE, 0.0f);
static constexpr Vector2 RIGHT(TILE_SIZE, 0.0f);
static constexpr Vector2 UP(0.0f, -TILE_SIZE);
static constexpr Vector2 DOWN(0.0f, TILE_SIZE);
static constexpr Vector2 STILL(0.0f, 0.0f);

class Player {
  std::array<Vector2, player_size> trailing_pieces;
  Vector2 head{starting_x, starting_y};
  Vector2 heading = STILL;
  Color color{0, 255, 0, 0};

 public:
  int score = 0;
  void onKeyDown(KeyCode key) noexcept;
  void render(const Renderer& renderer) const noexcept;

  void update() noexcept;
  void reset() noexcept;
  bool isSelfColliding() const noexcept;
  bool isColliding(Vector2 pos) const noexcept;
  bool isInside(Rectangle bounds) const noexcept;
  inline Vector2 getPos() const noexcept { return head; }
};