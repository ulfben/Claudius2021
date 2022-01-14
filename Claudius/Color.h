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
static constexpr Color BLACK{0, 0, 0, ALPHA_OPAQUE};
static constexpr Color GREEN{0, 255, 0, ALPHA_OPAQUE};
static constexpr Color RED{255, 0, 0, ALPHA_OPAQUE};