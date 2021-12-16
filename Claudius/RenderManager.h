#pragma once

#include <vector>

struct Sprite;
struct Transform;
struct Rectangle;
struct Color;

struct RenderManager {
  struct RectEntry {
    const Rectangle& rect;
    const Color& color;
    const Transform& trans;
  };
    
 void Render(const Rectangle& rect, const Color& color,
                             const Transform& trans) {
    rectEntries.push_back({rect, color, trans});
  }

  void Clear() { rectEntries.clear(); }

  std::vector<RectEntry> rectEntries;
};
