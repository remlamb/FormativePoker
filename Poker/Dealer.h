#pragma once
#include "Deck.h"
#include "Player.h"

int constexpr PLAYERS = 5;
int constexpr NUMBER_OF_CARDS = 5;

class Dealer
{

private:
	Deck _deck;
	std::vector<Player> _players;
	const std::vector<std::string> _NAME_TABLE = {
		"Rhaenyra",
		"Daemon",
		"Alicent",
		"Viserys",
		"Criston",
	};

	void distribute();

public:
	Dealer();


	void DefineWinner();

	void  StartGame();



};

