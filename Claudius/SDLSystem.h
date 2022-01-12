#pragma once
#include "CoreIncludes.h"
class SDLSystem {
 public:
  explicit SDLSystem(unsigned flags) {
    const auto result = SDL_Init(flags);    
    if (result == -1) {
      throw SDLInitError();
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