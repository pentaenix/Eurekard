#include "Hand.h"
#include "Card.h"
#include <vector>

const int MAX_HAND_CARDS = 5;

Hand::Hand(Deck* _deck)
{
	deck = _deck;
	for (int i = 0; i < MAX_HAND_CARDS; ++i)
	{
		auto card = deck->GetCard();
		card->SetPosX(i * 180);
		card->SetPosY(300);
		card->SetHandCallBack(this, &Hand::UseCard);
		cards.push_back(card);
	}
}

void Hand::GetNextCardFromDeck()
{

}

void Hand::UseCard(Card * cardSelected)
{
	cardSelected->SetState(CardState::OnFieldUp);
}

void Hand::RemoveCards()
{
	std::vector<Card*> toBeRemove;
	for (auto iter = cards.begin(); iter != cards.end(); ++iter)
	{
		if ((*iter)->GetState() == CardState::OnFieldUp)
		{
			toBeRemove.push_back(*iter);
		}
	}
	for (auto card : toBeRemove)
	{
		cards.remove(card);
	}
}

void Hand::Draw()
{
	//for(auto car: cards)
	for (auto iter = cards.begin(); iter != cards.end(); ++iter)
	{
		if (iter != cards.end())
		{
			(*iter)->Update();
		}
	}

	RemoveCards();

	for (auto iter = cards.begin(); iter != cards.end(); ++iter)
	{ 
		if (iter != cards.end())
		{
			(*iter)->Draw();
		}
	}
}

