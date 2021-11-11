#include "Platform.h"

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

void Platform::Input()
{


}

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
