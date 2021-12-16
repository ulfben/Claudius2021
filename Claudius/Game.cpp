// 2019-12-05 Teemu Laiho
#include "Game.h"

#include <iostream>

#include "CoreIncludes.h"

constexpr KeyCode TranslateKeyCode(SDL_Keycode code) noexcept;

Game::Game() noexcept {
  // Player test, moving two players to collide with each other.
  playerOne.Initialize();
  apple.Initialize(10, 10);
}

void Game::run() noexcept {
  float dt = 1.0f / 60.0f;
  bool running = true;
  while (running = checkInputs()) {
    update(dt);
    render();
  }
}

void Game::update(double dt) {
  playerOne.update(dt);

  for (int i = 0; i < playerOne.player_score; i++) {
    if (playerOne.trans.GetPosition() ==
        playerOne.parts[i].trans.GetPosition()) {
      playerOne.ResetPlayer();
    }
  }

  // Player going out of X bounds.
  if (playerOne.trans.GetX() > width || playerOne.trans.GetX() < 0) {
    playerOne.ResetPlayer();
  }

  // Player going out of Y bounds.
  if (playerOne.trans.GetY() > height || playerOne.trans.GetY() < 0) {
    playerOne.ResetPlayer();
  }

  // Player collide on apple.
  if (playerOne.trans.GetPosition() == apple.trans.GetPosition()) {
    playerOne.player_score++;
    apple.trans.SetPosition((rand() % 125) * 10.0f, (rand() % 70) * 10.0f);
  }
}

void Game::render() const noexcept {
  renderer.enterFrame();
  playerOne.render(renderer);
  apple.render(renderer);
  renderer.exitFrame();
}

void Game::onKeyDown(KeyCode key) const noexcept { playerOne.onKeyDown(key); }

void Game::onKeyUp([[maybe_unused]] KeyCode key) const noexcept {}

bool Game::checkInputs() const noexcept {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        return false;
        break;
      case SDL_KEYDOWN:
        onKeyDown(TranslateKeyCode(e.key.keysym.sym));
        break;
      case SDL_KEYUP:
        onKeyUp(TranslateKeyCode(e.key.keysym.sym));
        break;
    }
  }
  return true;
}

constexpr KeyCode TranslateKeyCode(SDL_Keycode code) noexcept {
  switch (code) {
    case SDLK_ESCAPE:
      return KeyCode::ESCAPE;
      break;
    case SDLK_SPACE:
      return KeyCode::SPACE;
      break;
    case SDLK_RETURN:
      return KeyCode::ENTER;
      break;
    case SDLK_RETURN2:
      return KeyCode::ENTER;
      break;
    case SDLK_a:
      return KeyCode::A;
      break;
    case SDLK_b:
      return KeyCode::B;
      break;
    case SDLK_c:
      return KeyCode::C;
      break;
    case SDLK_d:
      return KeyCode::D;
      break;
    case SDLK_e:
      return KeyCode::E;
      break;
    case SDLK_f:
      return KeyCode::F;
      break;
    case SDLK_g:
      return KeyCode::G;
      break;
    case SDLK_h:
      return KeyCode::H;
      break;
    case SDLK_i:
      return KeyCode::I;
      break;
    case SDLK_j:
      return KeyCode::J;
      break;
    case SDLK_k:
      return KeyCode::K;
      break;
    case SDLK_l:
      return KeyCode::L;
      break;
    case SDLK_m:
      return KeyCode::M;
      break;
    case SDLK_n:
      return KeyCode::N;
      break;
    case SDLK_o:
      return KeyCode::O;
      break;
    case SDLK_p:
      return KeyCode::P;
      break;
    case SDLK_q:
      return KeyCode::Q;
      break;
    case SDLK_r:
      return KeyCode::R;
      break;
    case SDLK_s:
      return KeyCode::S;
      break;
    case SDLK_t:
      return KeyCode::T;
      break;
    case SDLK_u:
      return KeyCode::U;
      break;
    case SDLK_v:
      return KeyCode::V;
      break;
    case SDLK_w:
      return KeyCode::W;
      break;
    case SDLK_x:
      return KeyCode::X;
      break;
    case SDLK_y:
      return KeyCode::Y;
      break;
    case SDLK_z:
      return KeyCode::Z;
      break;
    case SDLK_LEFT:
      return KeyCode::LEFT_ARROW;
      break;
    case SDLK_RIGHT:
      return KeyCode::RIGHT_ARROW;
      break;
    case SDLK_UP:
      return KeyCode::UP_ARROW;
      break;
    case SDLK_DOWN:
      return KeyCode::DOWN_ARROW;
      break;
    default:
      return KeyCode::INVALID;
      break;
  }
}