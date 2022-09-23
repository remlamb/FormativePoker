// PokerV2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string> 
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"





int main()
{
	 /* //test constructeur et lecture de la carte
	Card laCard(Values::deux, Suits::Spades);
	laCard.readACard();*/
	

	/* Verif creation du deck
	Deck _deck = Deck();	
	_deck.showDeck();
	*/

	Dealer dealer;
	dealer.StartGame();

	return 0;

}
