#include <iostream>
#include <random>
#include "Deck.h"


Deck::Deck() {
    for (int i = 0; i < 4; i++) {
        for (int x = 0; x < 13; x++) {
            _deck.emplace_back(Card(Values(x), Suits(i)));
        }
    }
};

void Deck::Shuffle() {
    std::shuffle(this->_deck.begin(), this->_deck.end(), std::random_device()); //fonction qui melange entre debut et fin
};

Card Deck::getCard() {
    Card pickedCard = _deck.front();
    _deck.erase(_deck.begin());
    return pickedCard;
};

void Deck::showDeck() { //pour le debug
    for (Card c : _deck) {
        c.readACard();
    }
};
