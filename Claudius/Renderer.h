#pragma once
#include "CoreIncludes.h"
class Renderer {
  SDL_Renderer* renderer = nullptr;

 public:
  explicit Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
      throw std::runtime_error(SDL_GetError());
    }
  }
  ~Renderer() { SDL_DestroyRenderer(renderer); }
  Renderer(const Renderer&) = delete;
  Renderer(Renderer&&) = delete;
  Renderer& operator=(const Renderer&) = delete;
  Renderer& operator=(Renderer&&) = delete;

  SDL_Renderer* getPtr() const noexcept { return renderer; }
};