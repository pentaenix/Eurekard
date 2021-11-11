#include <iostream>
#include "SDL.h"
#include "Platform.h"
#include "Image.h"

Image testImage;
int init()
{
	auto platform = Platform::GetPtr();
	platform->InitWindow();
	testImage.LoadImage("image.png");
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
	testImage.Draw();
	platform->RenderWindow();
}

int input()
{


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