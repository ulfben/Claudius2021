#pragma once
#include "CoreIncludes.h"
class Renderer {
  SDL_Renderer* renderer = nullptr;
  Color backgroundColor;

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

  void setDrawColor(const Color& c) const noexcept {
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
  }

  void enterFrame() const noexcept {
    setDrawColor(backgroundColor);
    SDL_RenderClear(renderer);
  }
  void render(const Rectangle& rect, const Color& color,
              const Transform& trans) const noexcept {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect sdlrect{static_cast<int>(trans.position.x),
                     static_cast<int>(trans.position.y), rect.w, rect.h};
    SDL_RenderFillRect(renderer, &sdlrect);
  }
  void exitFrame() const noexcept {
    SDL_RenderPresent(renderer);
    SDL_Delay(1000 / 20);
  }
};