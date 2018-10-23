#pragma once

#include <queue>

#include "Card.h"

class Player
{
public:
	Player();
	~Player();

	int GetNumberOfCards();

	bool HasLost();
	Card* GetNextCard();
	void AddCard(Card* card);


private:
	std::queue<Card*> deck;
};

