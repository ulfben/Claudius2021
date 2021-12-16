#pragma once
#include "CoreIncludes.h"
class SDLSystem {
 public:
  explicit SDLSystem(unsigned flags = SDL_INIT_EVERYTHING) {
    const auto result = SDL_Init(flags);    
    if (result == -1) {
      throw std::runtime_error(SDL_GetError());
    }
  }
  ~SDLSystem() noexcept { 
      SDL_Quit();
  }
  SDLSystem(const SDLSystem&) = delete;
  SDLSystem(SDLSystem&&) = delete;
  SDLSystem& operator=(const SDLSystem&) = delete;
  SDLSystem& operator=(SDLSystem&&) = delete;
};