#include "Game.h"
#include "CoreIncludes.h"
#include "KeyCode.h"

void Game::run() noexcept {
  respawnApple();
  while (running) {
    readInputs();
    update();
    render();
    SDL_Delay(FRAME_DELAY_MS);
  }
}

void Game::respawnApple() noexcept {
  xoshiro256ss rng{timer.ticks()};
  apple.respawn(rng);
  while (snake.isColliding(apple.getPos())) {
    apple.respawn(rng);
  }
}

void Game::update() noexcept {
  snake.update();
  if (snake.isColliding(apple.getPos())) {
    snake.grow();
    return respawnApple();
  }
  if (snake.isOutsideOf(stage) || snake.isSelfColliding()) {
    return snake.respawn();
  }
}

void Game::render() const noexcept {
  renderer.enterFrame();
  snake.render(renderer);
  apple.render(renderer);
  renderer.exitFrame();
}

void Game::onKeyDown(KeyCode key) noexcept {
  if (key == KeyCode::INVALID) {
    return;
  }
  if (key == KeyCode::ESCAPE) {
    running = false;   
  } else {
    snake.onKeyDown(key);
  }  
}

void Game::readInputs() noexcept {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        onKeyDown(TranslateKeyCode(e.key.keysym.sym));
        break;
      default:
        break;
    }
  }
}