#include "Card.h"
#include <sstream>
#include <fstream>

void Card::Load(std::string data, std::string pathCardDown, std::string pathCardUp)
{
    faceDown = new Button(pathCardDown, posX, posY);
    faceUp = new Button(pathCardUp, posX, posY);
}

void Card::ReadFile(std::string path)
{
    std::ifstream inFile(path);
    std::string line;
    std::string entry, value;

   
    while(std::getline(inFile,line))
    {
        std::stringstream ss(line);
        std::getline(ss,entry,' ');
        if(entry == "defense"){
            std::getline(ss, value, ' ');
            std::getline(ss, value, '\n');
            int tmp_int = stoi(value);
            SetDefense(tmp_int);
        }
        else if(entry == "attack"){
            std::getline(ss, value, ' ');
            std::getline(ss, value, '\n');
            int tmp_int = stoi(value);
            SetAttack(tmp_int);
        }
        else if(entry == "type"){
            std::getline(ss, value, ' ');
            std::getline(ss, value, '\n');
            int tmp_int = stoi(value);
            type = (CardType)tmp_int;
        }
        else if(entry == "pathImageUp"){
            std::getline(ss, value, ' ');
            std::getline(ss, value, '\n');
            //path=value;
        }
    }
    inFile.close();
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