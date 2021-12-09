#include "Game.h"
#include "Platform.h"
#include "stdlib.h"
#include "time.h"
#define ESC '\x1B'

Game::Game()
{
	
}

int Game::Init()
{
	srand(time(NULL));
	auto platform = Platform::GetPtr();
	platform->InitWindow();
	auto cardManager = CardManager::GetPtr();
	cardManager->Load("Resources/cards.list");
	p1 = new Player();
	return 0;
}

void Game::Update()
{

}

void Game::Draw()
{
	auto platform = Platform::GetPtr();
	platform->ClearWindow();
	p1->Draw();
	platform->RenderWindow();
}

int Game::Input()
{
	auto platform = Platform::GetPtr();
	auto key = platform->Input();
	return key;
}

void Game::GameLoop()
{
	Init();
	while (escape != ESC)
	{
		escape = Input();
		Update();
		Draw();
	}
}
