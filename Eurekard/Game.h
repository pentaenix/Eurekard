#pragma once
#include "Button.h"
#include "cardManager.h"
#include "Player.h"

class Game
{
private:
	Player *p1;
	
	int escape = 0;
	int Init();
	void Update();
	void Draw();
	int Input();
public:
	Game();
	void GameLoop();
};

