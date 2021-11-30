#pragma once
#include "Button.h"

class Game
{
private:
	Button* testButton;
	int escape = 0;
	int Init();
	void Update();
	void Draw();
	int Input();
public:
	void GameLoop();
};

