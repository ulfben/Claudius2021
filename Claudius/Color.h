#pragma once
#include <cstdint>
class Color {
 public:
  using color_value_t = uint8_t;
  Color();
  Color(const Color& rhs);
  Color(color_value_t r, color_value_t g, color_value_t b, color_value_t a);

  void SetColor(color_value_t r, color_value_t g, color_value_t b, color_value_t a) noexcept;  
   
  color_value_t r = 0;
  color_value_t g = 0;
  color_value_t b = 0;
  color_value_t a = 1;
};