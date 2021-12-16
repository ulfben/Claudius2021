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
  Transform parts[player_size];
  Transform trans{starting_x, starting_y, 0};
  Color color{0, 255, 0, 0};
  Rectangle rect{0, 0, size, size};
  int score = 0;

  void onKeyDown(KeyCode key) noexcept;  
  void render(const Renderer& renderer) const noexcept;

  void update(double dt) noexcept;
  void reset();

  bool moving_right = false;
  bool moving_left = false;
  bool moving_up = false;
  bool moving_down = false;  

  float x_array_difference[player_size] = {};
  float y_array_difference[player_size] = {};

 
};