#include <iostream>

#include "CoreIncludes.h"
#include "Game.h"
#undef main

int main() {
  try {
    Game game;
    game.run();
  } catch (const SDLInitError& e) {
    std::cerr << "SDL failed to initialize. Error: " << e.what();
  } catch (const SDLError& e) {
    std::cerr << "SDL error: " << e.what();
  } catch (...) {
    std::cerr << "Unrecognized exception. Exiting.";
  }
  return 0;
}
