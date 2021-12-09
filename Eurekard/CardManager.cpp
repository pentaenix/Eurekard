#include "CardManager.h"
#include <sstream>
#include <fstream>
#include <iostream>

CardManager* CardManager::ptr = nullptr;

CardManager::CardManager()
{

}

std::vector<Card*> CardManager::GetCards()
{
    return cards;
}

CardManager* CardManager::GetPtr()
{
    if (ptr == nullptr)
    {
        ptr = new CardManager();
    }
    return ptr;
}

bool CardManager::Load(const std::string& path)
{
    std::ifstream file(path);
    std::string line; 
    if (file.is_open())
    {
        while (getline(file, line))
        {
            try 
            {
                Card* card = new Card();
                card->Load(line);
                cards.push_back(card);
            }
            catch (...)
            {
                std::cout << "Load Error "<< line;
            }

        }
    }
    else
    {
        std::cout << "Card list file was not locate";
        return false;
    }
    file.close();
    return true;
}
