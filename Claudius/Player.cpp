#include "Player.h"

#include <algorithm>
#include <cmath>

void Player::render(const Renderer& renderManager) const noexcept {
  renderManager.setDrawColor(color);
  renderManager.render(head);
  for (auto p : trailing_pieces) {
    renderManager.render(p);
  }
}

bool Player::isColliding(Vector2 pos) const noexcept {
  return std::find(trailing_pieces.begin(), trailing_pieces.end(), pos) !=
         trailing_pieces.end();
}

bool Player::isSelfColliding() const noexcept { return isColliding(head); }

bool Player::isInside(Rectangle bounds) const noexcept {
  return isBetween(head.x, bounds.x, bounds.w) &&
         isBetween(head.y, bounds.y, bounds.h);
}

void Player::update() noexcept {
  for (auto i = trailing_pieces.size() - 1; i > 0; i--) {
    trailing_pieces[i] = trailing_pieces[i - 1];
  }
  trailing_pieces[0] = head;
  head += heading;
}

void Player::onKeyDown(KeyCode key) noexcept {
  if (key == KeyCode::LEFT_ARROW) {
    heading = LEFT;
  } else if (key == KeyCode::RIGHT_ARROW) {
    heading = RIGHT;
  } else if (key == KeyCode::UP_ARROW) {
    heading = UP;
  } else if (key == KeyCode::DOWN_ARROW) {
    heading = DOWN;
  }
}

void Player::reset() noexcept {
  score = 0;
  heading = STILL;
  head = {starting_x, starting_y};
}