#include "Button.h"
#include <iostream>
#include "Platform.h"

void Button::Draw()
{
    if(ButtonState::inactive == state){
        imgInactive.Draw();
    }else if(ButtonState::highlighted == state){
        imgHighlighted.Draw();
    }else{
        imgPressed.Draw();
    }
}

Button::Button(std::string imgName, int x, int y)
{
    imgInactive.LoadImage(imgName+"Inactive.png");
    imgHighlighted.LoadImage(imgName+"Highlighted.png");
    imgPressed.LoadImage(imgName+"Pressed.png");
    imgInactive.SetPosX(x);
    imgInactive.SetPosY(y);

    imgHighlighted.SetPosX(x);
    imgHighlighted.SetPosY(y);

    imgPressed.SetPosX(x);
    imgPressed.SetPosY(y);

    width = imgInactive.GetWidth();
    height = imgInactive.GetHeight();

    posX = x;
    posY = y;
}

void Button::SetEvents(Event* _highlighted, Event* _pressed, Event* _inactive)
{
    this->highlighted = _highlighted;
    this->pressed = _pressed;
    this->inactive = _inactive;
}

bool Button::MouseBox(int m_x,int m_y)
{
    return m_x >= posX && m_x <= posX + width && m_y >= posY && m_y <= posY + height;
}

void Button::Update()
{
    int mouseX=0, mouseY=0, mouseState=0;
    auto platform = Platform::GetPtr();
    platform->GetMouseInfo(mouseX,mouseY,mouseState);
    /*
        (posX,posY)
        P----------------*
        |         M      | 
        |                |
        *----------------F (posX+width,posY+heigth)
    */
    if (MouseBox(mouseX, mouseY) && mouseState == 1)
    {
        state = ButtonState::pressed;
    }
    else if (MouseBox(mouseX,mouseY))
    {    
        state = ButtonState::highlighted;
     
    }   
    else
    {
        state = ButtonState::inactive;
    }
}
