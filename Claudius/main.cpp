#include "CoreIncludes.h"
#include <iostream>
#include "Game.h"
#undef main

int main() {
  try {
    Game game;
    game.run();
  } catch (const std::runtime_error& e) {
    std::cerr << e.what();
  } catch (...) {
    std::cerr << "Unrecognized exception. Exiting.";
  }
  return 0;
}
