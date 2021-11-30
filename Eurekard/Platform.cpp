#include "Platform.h"
#include <iostream>

Platform* Platform::ptr = nullptr;

void Platform::InitWindow()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw "ERROR ON LAUNCH";
	}
	else
	{
		window = SDL_CreateWindow("Eurekard", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if(!window)
        {
            throw "ERROR ON LAUNCH: WINDOW";
        }
        else
        {
			render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        }
		if(!render)
		{ 
			throw "ERROR ON LAUNCH: RENDER";
		}
		else
		{
			SDL_SetRenderDrawColor(render, 0, 0, 0, 1);
		}
	}

}
void Platform::GetMouseInfo(int& m_mouseX, int& m_mouseY, int& m_mouseState)
{
	m_mouseX = mouseX;
	m_mouseY = mouseY;
	m_mouseState = mouseState;
}

int Platform::Input()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			std::cout << "mouse ";
			mouseState = 1;
		}
		if (e.type == SDL_MOUSEBUTTONUP)
		{
			std::cout << "mouse ";
			mouseState = 0;
		}
		if (e.type == SDL_MOUSEMOTION)
		{
			std::cout << "x: " << e.motion.x << std::endl;
			mouseX = e.motion.x;
			std::cout << "y: " << e.motion.y << std::endl;
			mouseY = e.motion.y;
		}
		if(e.type == SDL_KEYDOWN)
		{
			return e.key.keysym.sym;
		}
	}
}
/*
if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				return std::cout << "SDLK_ESCAPE ";
			}
*/
void Platform::Draw(const Image& img)
{


}

Platform::Platform()
{

}


Platform::~Platform()
{
	delete ptr;
}

Platform* Platform::GetPtr()
{
	if (ptr == nullptr)
	{
		ptr = new Platform();
	}
	return ptr;
}

void Platform::ClearWindow()
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 1);
	SDL_RenderClear(render);
}

void Platform::RenderWindow()
{
	SDL_RenderPresent(render);
}

SDL_Renderer* Platform::GetRender()
{
	return render;
}
