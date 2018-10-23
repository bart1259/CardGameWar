#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

int Player::GetNumberOfCards()
{
	return deck.size();
}

//Returns wheter or not the player has lost
bool Player::HasLost()
{
	if (deck.size() == 0) {
		return true;
	}
	return false;
}

//Get the next card
Card * Player::GetNextCard()
{
	Card* ret = deck.front();
	deck.pop();
	return ret;
}

//Add card to players deck
void Player::AddCard(Card * card)
{
	deck.push(card);
}
