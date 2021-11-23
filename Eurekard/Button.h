#pragma once
#include "Image.h"
#include "Event.h"

enum ButtonState
{
    inactive,
    highlighted,
    pressed
};

class Button 
{
private:
    Event* inactive, *highlighted, *pressed;
    Image imgInactive;
    Image imgHighlighted;
    Image imgPressed;
    int posX;
    int posY;
    int width, height;
    ButtonState state = ButtonState::inactive;
    bool MouseBox(int m_x, int m_y);

public:
    Button(std::string imgName, int x, int y);
    void SetEvents(Event* highlighted, Event* pressed, Event* inactive);
    void Draw();
    void Update(int mouseX, int mouseY, int mouseState);
/*
Atributos
evento
estado -> 
inactive, highlighted, pressed ---> apuntadores funciones contructor

Metodos ?
OnClick();
OnRelease();
Draw();
~Button();
*/

};
