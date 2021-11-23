#include "Image.h"
#include "SDL_image.h"
#include "Platform.h"

void Image::LoadImage(const std::string& path)
{
    source=path;
    SDL_Surface* loadedImg = IMG_Load(path.c_str());
    width = loadedImg->w;
    height = loadedImg->h;
    image = SDL_CreateTextureFromSurface(Platform::GetPtr()->GetRender(), loadedImg);
}

int Image::GetWidth()
{
    return width;
}

void Image::SetWidth(int m_width)
{
    width=m_width;
}

int Image::GetHeight()
{
    return height;
}

void Image::SetHeight(int m_height)
{
    height=m_height;
}

int Image::GetPosX()
{
    return posX;
}

int Image::GetPosY()
{
    return posY;
}

void Image::SetPosX(int m_posX)
{
    posX=m_posX;
}
void Image::SetPosY(int m_posY)
{
    posY=m_posY;
}

std::string Image::GetSource()
{
    return source;
}

void Image::Draw()
{
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    rect.w = width;
    rect.h = height;
    SDL_RenderCopyEx(Platform::GetPtr()->GetRender(), image, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
}