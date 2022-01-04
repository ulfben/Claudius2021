#pragma once
#include <cstdint>
struct Color { 
  using color_value_t = uint8_t;    
  color_value_t r = 0;
  color_value_t g = 0;
  color_value_t b = 0;
  color_value_t a = 255;
};