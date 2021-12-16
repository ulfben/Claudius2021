#pragma once
#include "CoreIncludes.h"
class Window {
  SDL_Window* window = nullptr;

 public:
  Window(std::string_view name, unsigned width, unsigned height) {
    window = SDL_CreateWindow(name.data(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, width, height,
                              SDL_WindowFlags::SDL_WINDOW_OPENGL);
    if (window == nullptr) {
      throw std::runtime_error(SDL_GetError());
    }
  }
  ~Window() { SDL_DestroyWindow(window); }
  Window(const Window&) = delete;
  Window(Window&&) = delete;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = delete;

  SDL_Window* getPtr() const noexcept { return window; }
};