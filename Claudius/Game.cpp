// 2019-12-05 Teemu Laiho

#include "Game.h"

#include <iostream>

#include "RenderManager.h"

Game::Game() {
  // Player test, moving two players to collide with each other.
  playerOne.Initialize();
  apple.Initialize(10, 10);
}

void Game::Update(double dt) {
  playerOne.Update(dt);

  for (int i = 0; i < playerOne.player_score; i++) {
    if (playerOne.trans.GetPosition() ==
        playerOne.parts[i].trans.GetPosition()) {
      playerOne.ResetPlayer();
    }
  }

  // Player going out of X bounds.
  if (playerOne.trans.GetX() > width || playerOne.trans.GetX() < 0) {
    playerOne.ResetPlayer();
  }

  // Player going out of Y bounds.
  if (playerOne.trans.GetY() > height || playerOne.trans.GetY() < 0) {
    playerOne.ResetPlayer();
  }

  // Player collide on apple.
  if (playerOne.trans.GetPosition() == apple.trans.GetPosition()) {
    playerOne.player_score++;
    apple.trans.SetPosition((rand() % 125) * 10.0f, (rand() % 70) * 10.0f);
  }
}

void Game::Render(RenderManager& renderManager) {
  playerOne.Render(renderManager);
  apple.Render(renderManager);
}

void Game::OnKeyDown(KeyCode key) { playerOne.OnKeyDown(key); }

void Game::OnKeyUp([[maybe_unused]]KeyCode key) {}
