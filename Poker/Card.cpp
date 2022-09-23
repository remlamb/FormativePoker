#include "Card.h"
#include <iostream>


Card::Card(Values theValues, Suits theSuits) {
    _theValues = theValues;
    _theSuits = theSuits;
};


std::string Card::suitsToString() {
    switch (_theSuits) {
        case Suits::Spades:
            return "Spades";

        case Suits::Clubs:
            return "Clubs";

        case Suits::Hearts:
            return "Hearts";

        case Suits::Diamonds:
            return "Diamonds";

        default:
            break;
        }
};

std::string Card::valuesToString() {
    switch (_theValues) {
        case Values::deux:
            return "2";

        case Values::trois:
            return "3";

        case Values::quatre:
            return "4";

        case Values::cinq:
            return "5";

        case Values::six:
            return "6";

        case Values::sept:
            return "7";

        case Values::huit:
            return "8";

        case Values::neuf:
            return "9";

        case Values::dix:
            return "10";

        case Values::Jack:
            return "Jack";

        case Values::Queen:
            return "Queen";

        case Values::King:
            return "King";

        case Values::As:
            return "As";

        default:
            break;
        }
};

void Card::readACard(){
    std::cout << Card::valuesToString() << " of " << Card::suitsToString() << "\n";
};

bool Card::compareCardValues(Card a, Card b) {
    if (a._theValues < b._theValues) {
        return true;
    }
    return false;
};


