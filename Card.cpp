#include "Card.h"

Card::Card(Suit suit, Value cardValue)
{
	_cardSuit = suit;
	_cardValue = cardValue;
}

Card::~Card()
{
}

std::string Card::ToString()
{
	//Set string suit based on card suit
	std::string suitString;
	switch (_cardSuit)
	{
	case Card::Hearts:
		suitString = std::string("Hearts");
		break;
	case Card::Diamonds:
		suitString = std::string("Diamonds");
		break;
	case Card::Clubs:
		suitString = std::string("Clubs");
		break;
	case Card::Spades:
		suitString = std::string("Spades");
		break;
	}

	//Set value string based on card value
	std::string valueString;
	switch (_cardValue)
	{
	case Value::Ace:
		valueString = std::string("Ace");
		break;
	case Value::King:
		valueString = std::string("King");
		break;
	case Value::Queen:
		valueString = std::string("Queen");
		break;
	case Value::Jack:
		valueString = std::string("Jack");
		break;
	default:
		valueString = std::to_string(_cardValue);
		break;
	}

	std::ostringstream stringBuilder;
	stringBuilder << valueString << " of " << suitString;

	return stringBuilder.str();
}

bool operator> (const Card& lhs, const Card& rhs) {


	return lhs._cardValue > rhs._cardValue;
}

bool operator==(const Card & lhs, const Card & rhs)
{
	return lhs._cardValue == rhs._cardValue;
}
