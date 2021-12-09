#pragma once
#include "Deck.h"
#include "Hand.h"

class Player
{
private:
	int mana;
	int health;
	Deck deck;
	Hand hand;
public:
	Player();
	~Player() {};
	void Draw();
};

