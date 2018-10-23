#pragma once

#include <string>
#include <sstream>

class Card
{
public:

	enum Suit
	{
		Hearts = 0,
		Diamonds = 1,
		Clubs = 2,
		Spades = 3,
		NullSuit = 4
	};

	enum Value
	{
		Two = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Ten = 10,
		Jack = 11,
		Queen = 12,
		King = 13,
		Ace = 14,
		NullValue = 15
	};

	Card(Suit suit, Value cardValue);
	~Card();

	std::string ToString();

	friend bool operator> (const Card &lhs, const Card &rhs);
	friend bool operator== (const Card &lhs, const Card &rhs);

private:
	Suit _cardSuit;
	Value _cardValue;
};

