#pragma once
#include <cstdint>
struct Color { 
  using color_value_t = uint8_t;    
  void SetColor(color_value_t red, color_value_t green, color_value_t blue,
                color_value_t alpha = 255) noexcept {
    this->r = red;
    this->g = green;
    this->b = blue;
    this->a = alpha;
  }

  color_value_t r = 0;
  color_value_t g = 0;
  color_value_t b = 0;
  color_value_t a = 255;
};