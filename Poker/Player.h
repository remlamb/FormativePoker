#pragma once
#include <vector>
#include "Card.h"
#include "Pattern.h"

class Player
{
private:

	std::string _playerName;
	std::vector<Card> _playerHand;	
	
public:
	Player(std::string playerName);
	void AddCard(Card card);
	void sortHand();
	void ToString();

	Pattern GetPattern();
	std::string getName();

};

