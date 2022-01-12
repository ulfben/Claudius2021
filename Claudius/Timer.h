#pragma once
#include "CoreIncludes.h"
class Timer {
  const uint64_t counterFrequency = SDL_GetPerformanceFrequency();
  uint64_t then = SDL_GetPerformanceCounter();  
 public:  
  uint64_t ticks() const noexcept { return SDL_GetPerformanceCounter(); }
  
  float deltaSeconds() noexcept {
    const auto now = SDL_GetPerformanceCounter();
    const auto delta_time = now - then;
    then = now;
    return delta_time / static_cast<float>(counterFrequency);
  }
};