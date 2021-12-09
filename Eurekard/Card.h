#pragma once
#include "Button.h"
#include "Hand.h"

enum CardType{
	Monster,
	SpecialMonster,
	Effect
};

enum CardState {
	OnGraveyard,
	OnFieldUp,
	OnFieldDown,
	OnHand,
	OnDeck
};

class Card {
private:
	int defense;
	int attack;
	int posX;
	int posY;
	int mana;
	std::string pathImage;
	CardType type;
	CardState state;
	Button* faceUp;
	Hand* handObj;
	int indexHand = -1;
	
	void (Hand::* UseCard)(Card* card);

	
	void ReadFile(std::string pathFile);
	int GetValue(std::stringstream& ss, std::string& entry, std::string& value);
	std::string GetString(std::stringstream& ss, std::string& entry, std::string& value);
public:
	void Load(std::string pathFileData);
	void SetHandCallBack(Hand* handObj, void (Hand::* UseCard)(Card* card));
	int GetDefense();
	int GetAttack();
	void SetDefense(const int& def);
	void SetAttack(const int& atk);
	int GetPosX();
	int GetPosY();
	void SetState(CardState state);
	void SetPosX(const int& px);
	void SetPosY(const int& py);
	void Draw();
	void Update();
	int GetMana();
	void SetMana(const int& _mana);
	void SetButton(Button* faceUp);
	Button* GetButton();
	CardState GetState();
};