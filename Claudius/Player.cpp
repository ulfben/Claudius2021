#include "Player.h"

#include <cmath>
#include <iostream>

void Player::render(const Renderer& renderManager) const noexcept {
  renderManager.render(rect, color, trans);
  for (int i = 0; i < score; i++) {
    renderManager.render(rect, color, parts[i]);
  }
}

void Player::update([[maybe_unused]] double dt) {
  x_array_difference[0] = trans.GetX() - parts[0].GetX();
  y_array_difference[0] = trans.GetY() - parts[0].GetY();

  for (int i = 1; i < (player_size - 1); i++) {
    x_array_difference[i] = parts[i].GetX() - parts[i + 1].GetX();
    y_array_difference[i] = parts[i].GetY() - parts[i + 1].GetY();
  }

  if (moving_left == true) {
    trans.ChangePosition(-movement_speed, 0);
    parts[0].ChangePosition(x_array_difference[0], y_array_difference[0]);

    for (int i = 1; i < player_size; i++) {
      parts[i].ChangePosition(x_array_difference[i - 1],
                                    y_array_difference[i - 1]);
    }
  } else if (moving_right == true) {
    trans.ChangePosition(movement_speed, 0);
    parts[0].ChangePosition(x_array_difference[0], y_array_difference[0]);

    for (int i = 1; i < player_size; i++) {
      parts[i].ChangePosition(x_array_difference[i - 1],
                                    y_array_difference[i - 1]);
    }
  } else if (moving_up == true) {
    trans.ChangePosition(0, -movement_speed);
    parts[0].ChangePosition(x_array_difference[0], y_array_difference[0]);

    for (int i = 1; i < player_size; i++) {
      parts[i].ChangePosition(x_array_difference[i - 1],
                                    y_array_difference[i - 1]);
    }
  } else if (moving_down == true) {
    trans.ChangePosition(0, movement_speed);
    parts[0].ChangePosition(x_array_difference[0], y_array_difference[0]);

    for (int i = 1; i < player_size; i++) {
      parts[i].ChangePosition(x_array_difference[i - 1],
                                    y_array_difference[i - 1]);
    }
  }
}

void Player::onKeyDown(KeyCode key) noexcept {
  if (key == KeyCode::LEFT_ARROW) {
    moving_left = true;
    moving_right = false;
    moving_up = false;
    moving_down = false;
  } else if (key == KeyCode::RIGHT_ARROW) {
    moving_left = false;
    moving_right = true;
    moving_up = false;
    moving_down = false;
  } else if (key == KeyCode::UP_ARROW) {
    moving_left = false;
    moving_right = false;
    moving_up = true;
    moving_down = false;
  } else if (key == KeyCode::DOWN_ARROW) {
    moving_left = false;
    moving_right = false;
    moving_up = false;
    moving_down = true;
  }
}

void Player::reset() {
  score = 0;
  moving_right = false;
  moving_left = false;
  moving_up = false;
  moving_down = false;

  trans.SetPosition(starting_x, starting_y);
}