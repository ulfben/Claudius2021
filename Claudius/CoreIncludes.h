#pragma once
#include <codeanalysis\warnings.h>
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include <stdexcept>

static constexpr uint8_t TILE_SIZE = 10;
static constexpr uint8_t COLUMNS = 50;
static constexpr uint8_t ROWS = 50;
static constexpr auto STAGE_PIXEL_WIDTH = TILE_SIZE * COLUMNS;
static constexpr auto STAGE_PIXEL_HEIGHT = TILE_SIZE * ROWS;
static constexpr auto STAGE_CENTER_X = STAGE_PIXEL_WIDTH / 2;
static constexpr auto STAGE_CENTER_Y = STAGE_PIXEL_HEIGHT / 2;
static constexpr std::string_view GAME_TITLE = "Snake";

// narrow_cast(): a searchable way to do narrowing casts of values
template <class T, class U>
constexpr T narrow_cast(U&& u) noexcept {
  return static_cast<T>(std::forward<U>(u));
}