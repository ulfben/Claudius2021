#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"

struct RenderManager;

class Game
{
	Player playerOne;
	Apple apple;
	int width = 1024;
	int height = 768;
public:
	Game();	
	bool Enter(int& width, int& height, std::string& title);
	void Update(double dt);
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
	void OnKeyUp(KeyCode key);
};