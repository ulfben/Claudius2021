#pragma once
#include "Color.h"
#include "KeyCode.h"
#include "Rectangle.h"
#include "Renderer.h"
#include "Transform.h"
static constexpr size_t player_size = 50;
static constexpr float movement_speed = 10.0f;
static constexpr float starting_x = 300.0f;
static constexpr float starting_y = 300.0f;
static constexpr int size = 10;
struct Player {
  struct PlayerPart {
    Transform trans;
    Color color;
    Rectangle rect;
  };
  PlayerPart parts[player_size];
  Transform trans;
  Color color;
  Rectangle rect;
  void onKeyDown(KeyCode key) noexcept;
  void Initialize();
  void render(const Renderer& renderer) const noexcept;

  void update(double dt) noexcept;
  void ResetPlayer();

  bool moving_right = false;
  bool moving_left = false;
  bool moving_up = false;
  bool moving_down = false;
  bool new_snake = false;

  float x_array_difference[player_size] = {};
  float y_array_difference[player_size] = {};

  int player_score = 0;
};