#pragma once
#include "Button.h"

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
	std::string pathImage;
	CardType type;
	CardState state;
	Button* faceUp;
	Button* faceDown;
	void ReadFile(std::string pathFile);
	int GetValue(std::stringstream& ss, std::string& entry, std::string& value);
	std::string GetString(std::stringstream& ss, std::string& entry, std::string& value);
public:
	void Load(std::string pathFileData);

	int GetDefense();
	int GetAttack();
	void SetDefense(const int& def);
	void SetAttack(const int& atk);
	int GetPosX();
	int GetPosY();
	void SetPosX(const int& px);
	void SetPosY(const int& py);
	void Draw();
	void Update();
};

