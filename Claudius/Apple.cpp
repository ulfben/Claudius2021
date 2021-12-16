#pragma once

#include "Apple.h"

#include <iostream>

void Apple::Initialize(unsigned int width, unsigned int height) {
  color.SetColor(0, 255, 0, 0);
  rect.SetBounds(0, 0, width, height);
  trans.SetPosition(100, 200);  
}

void Apple::render(const Renderer& r) const noexcept{
  r.render(rect, color, trans);
}
