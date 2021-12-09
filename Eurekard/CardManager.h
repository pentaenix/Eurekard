#pragma once
#include "Card.h"
#include <vector>

class CardManager
{
private:
	std::vector<Card *> cards;
	CardManager();
	static CardManager* ptr;
public:
	bool Load(const std::string& path);
	static CardManager* GetPtr();

	std::vector<Card*> GetCards();
};

