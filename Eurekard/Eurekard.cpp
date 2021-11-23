#include <iostream>
#include "SDL.h"
#include "Platform.h"
#include "Image.h"
#include "Button.h"

Button *testButton;
int init()
{
	auto platform = Platform::GetPtr();
	platform->InitWindow();
	testButton = new Button("button",100,100);
	return 0;
}

void update()
{
	
}


void draw()
{
	auto platform = Platform::GetPtr();
	platform->ClearWindow();
	//Render
	testButton->Draw();
	platform->RenderWindow();
}
int m_mouseX = 0, m_mouseY = 0, m_mouseState = 0;
int input()
{
	
	auto platform = Platform::GetPtr();
	platform->Input(m_mouseX,m_mouseY,m_mouseState);
	testButton->Update(m_mouseX, m_mouseY, m_mouseState);

	return 0;
}


int main(int argc, char* args[])
{
	init();
	bool escape = false;
	
	while(!escape){
		input();
		update();
		draw();
	}
	return 0;
}