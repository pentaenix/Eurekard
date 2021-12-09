#pragma once
#include "Deck.h"
#include <list>

class Card;

class Hand
{
private:
	Deck* deck;
	std::list<Card*> cards;
	void RemoveCards();
public:
	Hand(Deck *_deck);
	void GetNextCardFromDeck();
	void UseCard(Card* card);
	void Draw();
};

