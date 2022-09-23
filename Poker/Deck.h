#pragma once
#include"Card.h"
#include<vector>

class Deck{

	private:
		std::vector<Card> _deck;

	public: 
		Deck();

		void Shuffle();

		Card getCard();

		void showDeck(); //pour le debug 

};
