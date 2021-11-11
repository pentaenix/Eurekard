#pragma once
#include "SDL.h"
#include <string>

class Image
{
private:
    SDL_Texture* image;
    int width, height, posX = 0, posY = 0;
    std::string source;
public:
    void Draw();
    void LoadImage(const std::string& path);
    int GetWidth();
    void SetWidth(int m_width);
    int GetHeight();
    void SetHeight(int m_height);    
    int GetPosX();
    int GetPosY();
    void SetPosX(int m_posX);
    void SetPosy(int m_posY);
    std::string GetSource();
    
};

