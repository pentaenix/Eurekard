#include "Deck.h"
#include "CardManager.h"

#define MAX 10

Deck::Deck()
{
	SelectCards();
}

void Deck::SelectCards()
{
	auto allCards = CardManager::GetPtr()->GetCards();
	if (allCards.size() == 0)
		return;
	for (int i = 0; i < MAX; ++i)
	{
		auto card = allCards[rand() % allCards.size()];
		Card* newCard = new Card();
		
		newCard->SetButton(card->GetButton());
		newCard->SetAttack(card->GetAttack());
		newCard->SetDefense(card->GetDefense());
		newCard->SetMana(card->GetMana());
		cards.push_back(newCard);
	}
}

Card* Deck::GetCard()
{
	auto card = *cards.begin();
	cards.pop_front();
	return card;
}

/*std::list<Card*> Deck::Get()
{
	return cards;
}
*/