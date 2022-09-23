#include "Dealer.h"
#include "Card.h"
#include <algorithm>
#include <iostream>



Dealer::Dealer() {
	for (int i = 0; i < PLAYERS; i++) {
		std::string newName = _NAME_TABLE[i];
		_players.emplace_back(Player(newName));
	}
	_deck = Deck();
}

void Dealer::distribute() {
	_deck.Shuffle();
	for (int i = 0; i < NUMBER_OF_CARDS; i++) {
		for (Player& player : _players) {
			Card card = _deck.getCard();
			player.AddCard(card);
		}
	}

};

void Dealer::DefineWinner() {
	Player playerGagnant = _players[0];	// Quelque manque de precision notamment egalite impossible avec ce systeme  //du coup on est sur une victoire du type premier arrivé premier servi ici le premier de la liste des Joueurs
	for (Player& player : _players) {		
			if (player.getName() != playerGagnant.getName()) { //pas comparer la main du meme joueur 
				if (player.GetPattern().PatternValue > playerGagnant.GetPattern().PatternValue) {					
					playerGagnant = player;					
				}

				else if (player.GetPattern().PatternValue == playerGagnant.GetPattern().PatternValue) {

						if (player.GetPattern().PatternValue == Pattern::PatternValue::Pair || player.GetPattern().PatternValue == Pattern::PatternValue::ThreeOfAKind || player.GetPattern().PatternValue == Pattern::PatternValue::FourOfAKind) {
							//std::cout << "egalite de patern : " << player.getName() << " et " << playerGagnant.getName();			
							if (player.GetPattern().firstValue > playerGagnant.GetPattern().firstValue) {
								playerGagnant = player;
								//std::cout << "      Gagnant en cours : " << playerGagnant.getName() << "\n";
							}
							else if (player.GetPattern().firstValue == playerGagnant.GetPattern().firstValue) {
								if (player.GetPattern().thirdValue > playerGagnant.GetPattern().thirdValue) {
									playerGagnant = player;
								}
								//std::cout << "egalite   " << "\n";

							}
							else if(player.GetPattern().firstValue < playerGagnant.GetPattern().firstValue) {
								//std::cout << "      perdant en cours : " << player.getName() << "\n";
							}
						}

						if (player.GetPattern().PatternValue == Pattern::PatternValue::TwoPairs || player.GetPattern().PatternValue == Pattern::PatternValue::FullHouse) {

							if (player.GetPattern().firstValue > playerGagnant.GetPattern().firstValue) { //je compare les first values qui sont la values la + elevé pour les doublepairs ou qui stock le threeofkind 
								playerGagnant = player;
							}
							else if(player.GetPattern().firstValue == playerGagnant.GetPattern().firstValue) {
								if (player.GetPattern().secondValue > playerGagnant.GetPattern().secondValue) {
									playerGagnant = player;
								}
								else if(player.GetPattern().secondValue == playerGagnant.GetPattern().secondValue) {
									if (player.GetPattern().thirdValue > playerGagnant.GetPattern().thirdValue) {
										playerGagnant = player;
									}
								}
							}
						}

						if (player.GetPattern().PatternValue == Pattern::PatternValue::Straight || player.GetPattern().PatternValue == Pattern::PatternValue::StraightFlush) {
							if (player.GetPattern().firstValue > playerGagnant.GetPattern().firstValue) {
								playerGagnant = player;
							}
						}
				}
			}
	}

	std::cout << "Winner is : " << playerGagnant.getName() << "\n";
};

void Dealer::StartGame() {
	this->distribute();
	for (Player& player : _players) {
		player.ToString();
	}
	DefineWinner();
};


