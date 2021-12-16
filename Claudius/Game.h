#pragma once

#include <string>
#include <vector>

#include "CoreIncludes.h"
#include "SDLSystem.h"
#include "Window.h"
#include "Renderer.h"

#include "Apple.h"
#include "KeyCode.h"
#include "Player.h"

constexpr static unsigned width = 500;
constexpr static unsigned height = 500;
constexpr static std::string_view title = "Snake";

class Game {
  SDLSystem sdl{SDL_INIT_EVERYTHING};
  Window window{title, width, height};
  Renderer renderer{window.getPtr()};  
  Player playerOne;
  Apple apple;    
  void update(double dt);
  void render() const noexcept;
  void onKeyDown(KeyCode key) const noexcept;
  void onKeyUp(KeyCode key) const noexcept;
  bool checkInputs() const noexcept;
 public:  
  void run() noexcept;
};

