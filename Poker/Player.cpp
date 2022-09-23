#include "Player.h"
#include "Pattern.h"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void Player::AddCard(Card card) {
    _playerHand.emplace_back(card);

}



void Player::sortHand() {
   std::sort(_playerHand.begin(), _playerHand.end(), Card::compareCardValues); 
}

void Player::ToString(){

    std::cout << _playerName << " player cards :" << "\n";
    sortHand();
    for (auto& card : _playerHand) {
        card.readACard();
    }

    std::cout << "\n" << _playerName << " Hand Score : ";
    std::cout << GetPattern().patternToString() << " of ";

    if (GetPattern().PatternValue == Pattern::PatternValue::Pair) {
        std::cout << GetPattern().firstValueToString(GetPattern().firstValue);
    }

    if (GetPattern().PatternValue == Pattern::PatternValue::Highcard) {
        std::cout << GetPattern().firstValueToString(GetPattern().thirdValue);
    }

    if (GetPattern().PatternValue == Pattern::PatternValue::ThreeOfAKind) {
        std::cout << GetPattern().firstValueToString(GetPattern().firstValue);
    }

    if (GetPattern().PatternValue == Pattern::PatternValue::TwoPairs) {
        std::cout << GetPattern().firstValueToString(GetPattern().secondValue) << " and " << GetPattern().firstValueToString(GetPattern().firstValue);
    }

    if (GetPattern().PatternValue == Pattern::PatternValue::FullHouse) {
        std::cout << GetPattern().firstValueToString(GetPattern().secondValue) << " and " << GetPattern().firstValueToString(GetPattern().firstValue);
    }

    if (GetPattern().PatternValue == Pattern::PatternValue::FourOfAKind) {
        std::cout << GetPattern().firstValueToString(GetPattern().firstValue);
    }

    if (GetPattern().PatternValue == Pattern::PatternValue::Flush || GetPattern().PatternValue == Pattern::PatternValue::StraightFlush) {
        std::cout << GetPattern().patternSuitsToString(GetPattern().Suit);
    }

    if (GetPattern().PatternValue == Pattern::PatternValue::Straight) {
        std::cout << GetPattern().firstValueToString(GetPattern().firstValue) << " to " << GetPattern().firstValueToString(GetPattern().thirdValue);
    }

    std::cout << "\n" << "\n";
}

Player::Player(std::string playerName) {
    _playerName = playerName;
}

Pattern Player::GetPattern() {
    Pattern result = Pattern();
    std::map<Values, int> countValues;
    std::map<Suits, int> countSuits;


    for (Card card1 : _playerHand) {
        int countValue = 0;
        int countSuit = 0;
        for (Card card2 : _playerHand){
            if (card1._theValues == card2._theValues) 
            {
                countValue++;
            }
            if (card1._theSuits == card2._theSuits) {
                countSuit++;
            }

        }
        countValues[card1._theValues] = countValue;
        countSuits[card1._theSuits] = countSuit;
    }

    for (auto countValue : countValues) {
        if (countValue.second == 2) {

            if (result.PatternValue == Pattern::PatternValue::Pair) {
                result.PatternValue = Pattern::PatternValue::TwoPairs;
                result.secondValue = result.firstValue;
                result.firstValue = countValue.first;
            }

            else if (result.PatternValue == Pattern::PatternValue::ThreeOfAKind) {
                result.PatternValue = Pattern::PatternValue::FullHouse;
                result.secondValue = countValue.first;
            }

            else {
                result.PatternValue = Pattern::PatternValue::Pair;
                result.firstValue = countValue.first;
            }
                       
        }

        if (countValue.second == 3) {

            if (result.PatternValue == Pattern::PatternValue::Pair){
                result.PatternValue = Pattern::PatternValue::FullHouse;
                result.secondValue = result.firstValue;
            }
            else{
                result.PatternValue = Pattern::PatternValue::ThreeOfAKind;
            }
            result.firstValue = countValue.first;
        }

        if (countValue.second == 4) {
            result.PatternValue = Pattern::PatternValue::FourOfAKind;
            result.firstValue = countValue.first;
        }

       //Si highcard  il l'est par default mais on stock la + grande valeur(Unique) quand meme pour comparer et trouver le vainqueur
        if (countValue.second == 1) {
            result.thirdValue = countValue.first;
        }

    }

    for (int z = 0; z < 9; z++) {
        if (_playerHand[0]._theValues == Values(z) && _playerHand[1]._theValues == Values(z + 1) && _playerHand[2]._theValues == Values(z + 2) && _playerHand[3]._theValues == Values(z + 3) && _playerHand[4]._theValues == Values(z + 4)) {
            result.PatternValue = Pattern::PatternValue::Straight;
            result.firstValue = _playerHand[0]._theValues;
            result.thirdValue = _playerHand[4]._theValues;
        }
    }

    for (auto countSuit : countSuits) {
        if (countSuit.second == 5) {
            if (result.PatternValue == Pattern::PatternValue::Straight) {
                result.PatternValue = Pattern::PatternValue::StraightFlush;
            }
            else {
                result.PatternValue = Pattern::PatternValue::Flush;
            }
            result.Suit = countSuit.first;
        }
    }




    return result;
}


std::string Player::getName() {
    return _playerName;
}




