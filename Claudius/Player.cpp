#include "Player.h"

#include <algorithm>
#include <cmath>

void Player::render(const Renderer& renderManager) const noexcept {
  renderManager.setDrawColor(color);
  for (const auto& p : body_segments) {
    renderManager.render(p);
  }
}

bool Player::isColliding(Vector2 pos) const noexcept {
  if (!hasTrailingSegments()) {
    return head() == pos;
  }
  const auto firstTrailingPiece = body_segments.begin() + 1;
  return std::any_of(
      firstTrailingPiece, body_segments.end(),
      [pos](const auto& piece) noexcept { return piece == pos; });
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
  if (key == KeyCode::LEFT_ARROW) {
    if (heading == RIGHT && hasTrailingSegments()) {  // no accidental suicides!
      return;
    } 
    heading = LEFT;
  } else if (key == KeyCode::RIGHT_ARROW) {
    if (heading == LEFT && hasTrailingSegments()) {
      return;
    }
    heading = RIGHT;
  } else if (key == KeyCode::UP_ARROW) {
    if (heading == DOWN && hasTrailingSegments()) {
      return;
    }
    heading = UP;
  } else if (key == KeyCode::DOWN_ARROW) {
    if (heading == UP && hasTrailingSegments()) {
      return;
    }
    heading = DOWN;
  }
}

void Player::respawn() noexcept {
  body_segments.clear();
  body_segments.emplace_back(STAGE_CENTER_X, STAGE_CENTER_Y);
  heading = STILL;
}