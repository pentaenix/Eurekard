#pragma once
#include "Button.h"
#include "Card.h"

class Game
{
private:
	Card* card;
	int escape = 0;
	int Init();
	void Update();
	void Draw();
	int Input();
public:
	void GameLoop();
};

