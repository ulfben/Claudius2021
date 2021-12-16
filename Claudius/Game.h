#pragma once

#include <string>
#include <vector>

#include "Apple.h"
#include "CoreIncludes.h"
#include "KeyCode.h"
#include "Player.h"
#include "Renderer.h"
#include "SDLSystem.h"
#include "Window.h"

constexpr static unsigned width = 500;
constexpr static unsigned height = 500;
constexpr static std::string_view title = "Snake";

class Game {
  Rectangle stage{0, 0, width, height};
  SDLSystem sdl{SDL_INIT_EVERYTHING};
  Window window{title, stage.w, stage.h};
  Renderer renderer{window.getPtr()};
  Player playerOne;
  Apple apple;
  void update() noexcept;
  void render() const noexcept;
  void onKeyDown(KeyCode key) noexcept;
  void onKeyUp(KeyCode key) const noexcept;
  bool checkInputs() noexcept;
  void respawnApple() noexcept;

 public:
  void run() noexcept;
  Game() = default;
};
