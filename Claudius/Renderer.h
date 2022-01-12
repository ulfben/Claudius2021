#pragma once
#include "CoreIncludes.h"
#include "Color.h"
#include "Coord.h"
#include "Rectangle.h"
class Renderer {
  SDL_Renderer* renderer = nullptr;
  Color bgColor;

 public:
  explicit Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
      throw SDLError();
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
    setDrawColor(bgColor);
    SDL_RenderClear(renderer);
  }

  void render(Coord pos) const noexcept {
    const SDL_Rect sdlrect{pos.x, pos.y, TILE_SIZE, TILE_SIZE};
    SDL_RenderFillRect(renderer, &sdlrect);
  }

  void render(Coord pos, Color color) const noexcept {
    setDrawColor(color);
    render(pos);    
  }

  void exitFrame() const noexcept {
    SDL_RenderPresent(renderer);
  }
};