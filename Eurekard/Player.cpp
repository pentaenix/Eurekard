#include "Player.h"

Player::Player(): hand(&deck) {
}

void Player::Draw()
{
	hand.Draw();
}