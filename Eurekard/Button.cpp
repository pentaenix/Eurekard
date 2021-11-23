#include "Button.h"
#include <iostream>

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

    width = imgInactive.GetHeight();
    height = imgInactive.GetWidth();

    posX = x;
    posX = y;
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

void Button::Update(int mouseX, int mouseY, int mouseState)
{
    /*
        (posX,posY)
        P----------------*
        |         M      | 
        |                |
        *----------------F (posX+width,posY+heigth)
    */
    if (MouseBox(mouseX,mouseY) && mouseState == 1)
    {    
        state = ButtonState::pressed;
        std::cout<<"pressed";
        /*if(ButtonState::inactive == state){
            //inactive->accion();
            std::cout<<"inactive";
        }else if(ButtonState::highlighted == state){
            //highlighted->accion();
            std::cout<<"highlighted";
        }else{
          //  (pressed->accion)();
              std::cout<<"pressed";
        }*/         
    }   
}
