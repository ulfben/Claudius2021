#pragma once
#include <cstdint>
static constexpr uint8_t ALPHA_OPAQUE = 255;
static constexpr uint8_t ALPHA_TRANSPARENT = 0;
struct Color {
  using color_value_t = uint8_t;
  color_value_t r = 0;
  color_value_t g = 0;
  color_value_t b = 0;
  color_value_t a = ALPHA_OPAQUE;
};