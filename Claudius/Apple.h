#pragma once
#include "Renderer.h"
#include "KeyCode.h"
#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"
struct Apple{		
	void render(const Renderer& r) const noexcept;
	void Initialize(unsigned int width, unsigned int height);

	Rectangle rect;
	Color color;
	Transform trans;		
	Transform trans;		
};