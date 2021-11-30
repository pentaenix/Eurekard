#include "Game.h"
#include "Platform.h"
#define ESC '\x1B'

int Game::Init()
{
	auto platform = Platform::GetPtr();
	platform->InitWindow();
	testButton = new Button("button", 100, 100);
	return 0;
}

void Game::Update()
{

}

void Game::Draw()
{
	auto platform = Platform::GetPtr();
	platform->ClearWindow();
	//Render
	testButton->Draw();
	platform->RenderWindow();
}

int Game::Input()
{
	auto platform = Platform::GetPtr();
	auto key = platform->Input();
	testButton->Update();
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