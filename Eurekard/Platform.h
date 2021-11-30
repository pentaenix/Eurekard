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
    int mouseX = 0, mouseY = 0, mouseState = 0;
public:    
    ~Platform();
    static Platform* GetPtr();
	void InitWindow();
	int Input();
    void GetMouseInfo(int &m_mouseX, int& m_mouseY, int& m_mouseState);
	void Draw(const Image& img);
    void ClearWindow();
    void RenderWindow();
    SDL_Renderer* GetRender();
};

