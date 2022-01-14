#include "Player.h"
#include <algorithm>

void Player::render(const Renderer& renderManager) const noexcept {
  renderManager.setDrawColor(GREEN);
  for (const auto& part : body) {
    renderManager.render(part);
  }
}

bool Player::isCollidingWith(Coord pos) const noexcept {
  if (!hasTail()) {
    return head() == pos;
  }
  const auto tailBegin = body.begin() + 1;
  return std::any_of(
      tailBegin, body.end(),
      [pos](const auto& piece) noexcept { return piece == pos; });
}

bool Player::isOutsideOf(Rectangle bounds) const noexcept {
  return !::isInside(head(), bounds);
}

bool Player::isSelfColliding() const noexcept {
  return hasTail() && isCollidingWith(head());
}

void Player::grow() noexcept {
  try {
    body.emplace_back(position());
  } catch (...) {
    /*swallowing exception. The game can keep running, the snake won't grow.*/
  }
}

void Player::update() noexcept {  
  std::shift_right(body.begin(), body.end(), 1);
  head() += heading;
}

void Player::onKeyDown(KeyCode key) noexcept {  
  if (key == KeyCode::LEFT_ARROW && heading != RIGHT) {    
    heading = LEFT;
  } else if (key == KeyCode::RIGHT_ARROW && heading != LEFT) {
    heading = RIGHT; 
  } else if (key == KeyCode::UP_ARROW && heading != DOWN) {
    heading = UP;
  } else if (key == KeyCode::DOWN_ARROW && heading != UP) {
    heading = DOWN;
  }
}

void Player::respawn() noexcept {
  body.clear();
  body.emplace_back(STAGE_CENTER_X, STAGE_CENTER_Y);
  heading = STILL;
}