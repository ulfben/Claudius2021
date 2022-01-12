#pragma once
#include "CoreIncludes.h"
enum class KeyCode{
	ESCAPE,SPACE,ENTER,
	A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
	LEFT_ARROW,RIGHT_ARROW,UP_ARROW,DOWN_ARROW,
	INVALID
};

constexpr KeyCode TranslateKeyCode(SDL_Keycode code) noexcept {
  switch (code) {
    case SDLK_ESCAPE:
      return KeyCode::ESCAPE;
      break;
    case SDLK_LEFT:
      return KeyCode::LEFT_ARROW;
      break;
    case SDLK_RIGHT:
      return KeyCode::RIGHT_ARROW;
      break;
    case SDLK_UP:
      return KeyCode::UP_ARROW;
      break;
    case SDLK_DOWN:
      return KeyCode::DOWN_ARROW;
      break;
    default:
      return KeyCode::INVALID;
      break;
  }
}