#include "Player.h"

#include <algorithm>
#include <cmath>

void Player::render(const Renderer& renderManager) const noexcept {
  renderManager.setDrawColor(color);
  for (auto& p : body_segments) {
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
  const auto pos = head();
  return ::isInside(pos, bounds);
}

void Player::grow() noexcept {
  try {
    body_segments.emplace_back(getPos());
  } catch (...) {
    /*swallowing exception. The game can keep running, the snake won't grow.*/
  }
}

void Player::update() noexcept {
  const auto new_head = head() + heading;
  std::rotate(body_segments.begin(), body_segments.begin() + 1,
              body_segments.end());
  head() = new_head;  
}

void Player::onKeyDown(KeyCode key) noexcept {
  if (key == KeyCode::LEFT_ARROW) {
    if (heading == RIGHT && hasTrailingSegments()) {
      return;
    }  // no accidental suicides!
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
  body_segments.emplace_back(starting_x, starting_y);
  heading = STILL;
}