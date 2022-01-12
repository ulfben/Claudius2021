#include "Player.h"
#include <algorithm>

void Player::render(const Renderer& renderManager) const noexcept {
  renderManager.setDrawColor(color);
  for (const auto& p : body_segments) {
    renderManager.render(p);
  }
}

bool Player::isColliding(Coord pos) const noexcept {
  if (!hasTrailingSegments()) {
    return head() == pos;
  }
  const auto firstTrailingPiece = body_segments.begin() + 1;
  return std::any_of(
      firstTrailingPiece, body_segments.end(),
      [pos](const auto& piece) noexcept { return piece == pos; });
}

bool Player::isOutsideOf(Rectangle bounds) const noexcept {
  return !isInside(bounds);
}

bool Player::isSelfColliding() const noexcept {
  return hasTrailingSegments() && isColliding(head());
}

bool Player::isInside(Rectangle bounds) const noexcept {
  return ::isInside(head(), bounds);
}

void Player::grow() noexcept {
  try {
    body_segments.emplace_back(getPos());
  } catch (...) {
    /*swallowing exception. The game can keep running, the snake won't grow.*/
  }
}

void Player::update() noexcept {
  std::shift_right(body_segments.begin(), body_segments.end(), 1);
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
  body_segments.clear();
  body_segments.emplace_back(STAGE_CENTER_X, STAGE_CENTER_Y);
  heading = STILL;
}