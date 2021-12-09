#pragma once
#include <list>

class Card;

class Deck
{
private:
	std::list<Card *> cards;
public:
	Deck();
	void SelectCards();
	Card* GetCard();
};

