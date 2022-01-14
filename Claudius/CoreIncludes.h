#pragma once
#include <codeanalysis\warnings.h>
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include <stdexcept>
#include <string_view>
#include "Coord.h"

static constexpr unsigned FRAME_DELAY_MS = 45;
static constexpr uint8_t TILE_SIZE = 10;
static constexpr uint8_t COLUMNS = 50;
static constexpr uint8_t ROWS = 50;
static constexpr auto STAGE_PIXEL_WIDTH = TILE_SIZE * COLUMNS;
static constexpr auto STAGE_PIXEL_HEIGHT = TILE_SIZE * ROWS;
static constexpr auto STAGE_CENTER_X = STAGE_PIXEL_WIDTH / 2;
static constexpr auto STAGE_CENTER_Y = STAGE_PIXEL_HEIGHT / 2;
static constexpr std::string_view GAME_TITLE = "Snake";

static constexpr Vector2 LEFT(-TILE_SIZE, 0);
static constexpr Vector2 RIGHT(TILE_SIZE, 0);
static constexpr Vector2 UP(0, -TILE_SIZE);
static constexpr Vector2 DOWN(0, TILE_SIZE);
static constexpr Vector2 STILL(0, 0);

// narrow_cast(): a searchable way to do narrowing casts of values
template <class T, class U>
constexpr T narrow_cast(U&& u) noexcept {
  return static_cast<T>(std::forward<U>(u));
}

// custom exception types
class SDLError : public std::runtime_error {
 public:  
  [[gsl::suppress(f.6, justification: "As long as it depends on std::runtime_error this ctor can not be marked noexcept. std::runtime_error can throw std::bad_alloc.")]]
  SDLError() : std::runtime_error(SDL_GetError()){};
};

class SDLInitError : public SDLError {};
