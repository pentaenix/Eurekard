#include "Card.h"
#include <sstream>
#include <fstream>

void Card::Load(std::string pathFileData)
{
    ReadFile(pathFileData);
    faceDown = new Button("Resources/CardDown", posX, posY);
    faceUp = new Button(pathImage + "CardUp", posX, posY);
}

void Card::ReadFile(std::string path)
{
    std::ifstream inFile(path);
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

int Card::GetPosX()
{
    return posX;
}

int Card::GetPosY()
{
    return posY;
}

void Card::SetPosX(const int& px)
{
    posX = px;
}

void Card::SetPosY(const int& py)
{
    posY = py;
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
        faceDown->Draw();    
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
        faceDown->Update();    
    }  
}