#pragma once
#include "SDL.h"
#include "Image.h"

class Platform
{
private:
    int width = 1024;
    int height = 720;
    SDL_Window* window;
    SDL_Renderer* render;
    Platform();
    static Platform* ptr;
public:    
    ~Platform();
    static Platform* GetPtr();
	void InitWindow();
	void Input(int& mouseX, int& mouseY, int& mouseState);
	void Draw(const Image& img);
    void ClearWindow();
    void RenderWindow();
    SDL_Renderer* GetRender();
};

