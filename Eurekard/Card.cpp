#include "Card.h"
#include <sstream>
#include <fstream>
#include "Hand.h"

void Card::Load(std::string pathFileData)
{
    ReadFile(pathFileData);
    faceUp = new Button(pathImage + "CardUp", posX, posY);
}

void Card::ReadFile(std::string path)
{
    std::ifstream inFile(path);
    //Mateo agregar validacion si el archivo no exite
    std::string line;
    std::string entry, value;
    while(std::getline(inFile,line))
    {
        std::stringstream ss(line);
        std::getline(ss, entry, ' ');
        if(entry == "defense")
        {
           SetDefense(GetValue(ss, entry, value));
        }
        else if(entry == "attack")
        {
            SetAttack(GetValue(ss, entry, value));
        }
        else if (entry == "mana")
        {
            SetMana(GetValue(ss, entry, value));
        }
        else if(entry == "type")
        {
            GetString(ss, entry, value);
            if (value =="Monster")
            {
                type = CardType::Monster;
            }
            else if (value == "SpecialMonster")
            {
                type = CardType::SpecialMonster;
            }
            else if (value == "Effect")
            {
                type = CardType::Effect;
            }
        }
        else if(entry == "pathImageUp")
        {
            GetString(ss, entry, value);
            pathImage = value;
        }
    }
    inFile.close();
}

int Card::GetValue(std::stringstream& ss, std::string& entry, std::string& value)
{
    std::getline(ss, entry, ' ');
    std::getline(ss, value, '=');
    std::getline(ss, value, '\n');
    return stoi(value);
}

std::string Card::GetString(std::stringstream & ss, std::string & entry, std::string & value)
{
    std::getline(ss, entry, ' ');
    std::getline(ss, value, '=');
    std::getline(ss, value, '\n');
    return value;
}

int Card::GetDefense()
{
    return defense;
}
        
int Card::GetAttack()
{
    return attack;
}
    
void Card::SetDefense(const int& def)
{
    defense = def;
}

void Card::SetAttack(const int& atk)
{
    attack = atk;
}

int Card::GetMana()
{
    return mana;
}

void Card::SetMana(const int& _mana)
{
    mana = _mana;
}

void Card::SetButton(Button* _faceUp)
{
    faceUp = _faceUp;
}

Button* Card::GetButton()
{
   return faceUp;
}

int Card::GetPosX()
{
    return posX;
}

int Card::GetPosY()
{
    return posY;
}

CardState Card::GetState()
{
    return state;
}
void Card::SetState(CardState _state)
{
    state = _state;
}

void Card::SetPosX(const int& px)
{
    posX = px;
    faceUp->SetPosX(posX);
}

void Card::SetPosY(const int& py)
{
    posY = py;
    faceUp->SetPosY(posY);
}

void Card::Draw()
{
    if (state == CardState::OnFieldUp)
    {
        faceUp->Draw();    
    }
    else if (state == CardState::OnFieldDown ||
             state == CardState::OnGraveyard ||
             state == CardState::OnHand ||
             state == CardState::OnDeck)
    {
        faceUp->Draw();
    }
}

void Card::Update()
{

    if (state == CardState::OnFieldUp)
    {
        faceUp->Update();    
    }
    else if (state == CardState::OnFieldDown ||
             state == CardState::OnGraveyard ||
             state == CardState::OnHand ||
             state == CardState::OnDeck)
    {
        faceUp->Update();
    }  


    if (faceUp->GetState() == ButtonState::pressed)
    {
        (handObj->*UseCard)(this);
    }
}


void Card::SetHandCallBack(Hand* _handObj, void (Hand::* _UseCard)(Card* card))
{
    handObj = _handObj;
    UseCard = _UseCard;
}