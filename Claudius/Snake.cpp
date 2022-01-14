#include "Snake.h"
#include <algorithm>

void Snake::render(const Renderer& renderManager) const noexcept {
  renderManager.setDrawColor(GREEN);
  for (const auto& part : body) {
    renderManager.render(part);
  }
}

bool Snake::isCollidingWith(Coord pos) const noexcept {
  if (!hasTail()) {
    return head() == pos;
  }
  const auto tailBegin = body.begin() + 1;
  return std::any_of(
      tailBegin, body.end(),
      [pos](const auto& piece) noexcept { return piece == pos; });
}

bool Snake::isOutsideOf(Rectangle bounds) const noexcept {
  bounds.h -= TILE_SIZE; 
  bounds.w -= TILE_SIZE;
  return !::isInside(head(), bounds);
}

bool Snake::isSelfColliding() const noexcept {
  return hasTail() && isCollidingWith(head());
}

void Snake::grow() noexcept {
  try {
    body.emplace_back(position());
  } catch (...) {
    /*swallowing exception. The game can keep running, the snake won't grow.*/
  }
}

void Snake::update() noexcept {  
  std::shift_right(body.begin(), body.end(), 1);
  head() += heading;
}

void Snake::onKeyDown(KeyCode key) noexcept {  
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

void Snake::respawn() noexcept {
  body.clear();
  body.emplace_back(STAGE_CENTER_X, STAGE_CENTER_Y);
  heading = STILL;
}