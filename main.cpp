
#include <iostream>
#include <vector>
#include <algorithm>
#include<ctime>

#include "Card.h"
#include "Player.h"

Player* player1;
Player* player2;

const int NUMBER_OF_PLAYERS = 2;

void war(Player* player1, Player* player2, std::vector<Card*> cards) {

	//If either player has lost, give them the oponent the cards and retun
	if (player1->HasLost() || player2->HasLost()) {
		Player* winner = player1;
		if (player2->HasLost()) {
			winner = player2;
		}
		for (auto it = cards.begin(); it != cards.end(); ++it)
		{
			winner->AddCard(*it);
		}
		return;
	}
	//Put one card each into the war pile
	Card* player1PutCard = player1->GetNextCard();
	Card* player2PutCard = player2->GetNextCard();
	cards.push_back(player1PutCard);
	cards.push_back(player2PutCard);

	std::cout << "Player 1 puts " << player1PutCard->ToString() << " into pile" << std::endl;
	std::cout << "Player 2 puts " << player2PutCard->ToString() << " into pile" << std::endl;


	//If either player has lost, give them the oponent the cards and retun
	if (player1->HasLost() || player2->HasLost()) {
		Player* winner = player1;
		if (player2->HasLost()) {
			winner = player2;
		}
		for (auto it = cards.begin(); it != cards.end(); ++it)
		{
			winner->AddCard(*it);
		}
		return;
	}

	Card* cardFromPlayer1 = player1->GetNextCard();
	Card* cardFromPlayer2 = player2->GetNextCard();

	std::cout << "Player 1 draws: " << cardFromPlayer1->ToString().c_str() << std::endl;
	std::cout << "Player 2 draws: " << cardFromPlayer2->ToString().c_str() << std::endl;


	if (*cardFromPlayer1 == *cardFromPlayer2) {
		//War
		std::cout << "War Continues!" << std::endl;
		cards.push_back(cardFromPlayer1);
		cards.push_back(cardFromPlayer2);
		war(player1, player2, cards);
	}
	else
	{
		if (*cardFromPlayer1 > *cardFromPlayer2) {
			//Player 1 has won
			std::cout << "Player 1 wins round" << std::endl;
			player1->AddCard(cardFromPlayer1);
			player1->AddCard(cardFromPlayer2);
			for (auto it = cards.begin(); it != cards.end(); ++it)
			{
				player1->AddCard(*it);
			}
		}
		else
		{
			//Player 2 has won
			std::cout << "Player 2 wins round" << std::endl;
			player2->AddCard(cardFromPlayer1);
			player2->AddCard(cardFromPlayer2);
			for (auto it = cards.begin(); it != cards.end(); ++it)
			{
				player2->AddCard(*it);
			}
		}
	}
}

int main() {

	std::cout << "War Simulator!" << std::endl;
	std::cout << "- To simulate the next turn press ENTER" << std::endl;
	std::cout << "Press the ENTER key to start" << std::endl;

	std::getchar();

	//Create players
	player1 = new Player();
	player2 = new Player();

	std::vector<Card*> cards;

	//Generate all cards
	//Loop through all suits
	for (int suit = Card::Suit::Hearts; suit != Card::Suit::NullSuit; suit++)
	{
		//Loop through all card values
		for (int value = Card::Value::Two; value != Card::Value::NullValue; value++)
		{
			cards.push_back(new Card(static_cast<Card::Suit>(suit),
				static_cast<Card::Value>(value)));
		}
	}

	//Seed random gnerator
	srand(time(NULL));

	//Shuffle
	std::random_shuffle(cards.begin(), cards.end());

	//Give players cards
	int index = 0;
	for (auto it = cards.begin(); it != cards.end(); ++it)
	{
		if (index % NUMBER_OF_PLAYERS == 0) {
			player1->AddCard(*it);
		}
		else if (index % NUMBER_OF_PLAYERS == 1) {
			player2->AddCard(*it);
		}
		index++;
	}
	int roundNumber = 1;
	while (!player1->HasLost() && !player2->HasLost())
	{
		std::cout << "Round: " << roundNumber << std::endl;

		Card* cardFromPlayer1 = player1->GetNextCard();
		Card* cardFromPlayer2 = player2->GetNextCard();

		std::cout << "Player 1 draws: " << cardFromPlayer1->ToString().c_str() << std::endl;
		std::cout << "Player 2 draws: " << cardFromPlayer2->ToString().c_str() << std::endl;


		if (*cardFromPlayer1 == *cardFromPlayer2) {
			//War
			std::cout << "War!" << std::endl;
			std::vector<Card*> cards;
			cards.push_back(cardFromPlayer1);
			cards.push_back(cardFromPlayer2);
			war(player1, player2, cards);
		}
		else
		{
			if (*cardFromPlayer1 > *cardFromPlayer2) {
				//Player 1 has won
				std::cout << "Player 1 wins round" << std::endl;
				player1->AddCard(cardFromPlayer1);
				player1->AddCard(cardFromPlayer2);
			}
			else
			{
				//Player 2 has won
				std::cout << "Player 2 wins round" << std::endl;
				player2->AddCard(cardFromPlayer1);
				player2->AddCard(cardFromPlayer2);
			}
		}
		std::cout << "Player one has " << player1->GetNumberOfCards() << " Cards" << std::endl;
		std::cout << "Player two has " << player2->GetNumberOfCards() << " Cards" << std::endl;
	
		roundNumber++;

		std::getchar();

	}

	if (player1->HasLost()) {
		std::cout << "Player 1 has won!" << std::endl;
	}
	else
	{
		std::cout << "Player 2 has won!" << std::endl;
	}

	//Cleanup memory
	for (auto it = cards.begin(); it != cards.end(); ++it)
	{
		delete *it;
	}
	delete player1;
	delete player2;

	system("pause");

	return 0;
}