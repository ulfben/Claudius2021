#pragma once
#include "Renderer.h"
#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"
constexpr static size_t width = 10;
struct Apple{		
	void render(const Renderer& r) const noexcept {
        r.render(rect, color, trans);
    }
	Rectangle rect{0, 0, width, width};
    Color color{0, 255, 0, 0};
    Transform trans{100, 200, 0};
};