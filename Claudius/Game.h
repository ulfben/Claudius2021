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



class Game {
  Rectangle stage{0, 0, STAGE_PIXEL_WIDTH, STAGE_PIXEL_HEIGHT};
  SDLSystem sdl{SDL_INIT_EVERYTHING};
  Window window{GAME_TITLE, stage.w, stage.h};
  Renderer renderer{window.getPtr()};
  Player playerOne;
  Apple apple;  
  void update() noexcept;
  void render() const noexcept;
  void onKeyDown(KeyCode key) noexcept;  
  bool checkInputs() noexcept;
  void respawnApple() noexcept;

 public:
  void run() noexcept;
  Game() = default;
};
