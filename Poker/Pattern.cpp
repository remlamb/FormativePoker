#include "Pattern.h"

std::string Pattern::patternToString() {
    switch (PatternValue) {
    case PatternValue::Highcard:
        return "Highcard";

    case PatternValue::Pair:
        return "Pair";

    case PatternValue::TwoPairs:
        return "TwoPairs";

    case PatternValue::ThreeOfAKind:
        return "ThreeOfAKind";

    case PatternValue::Straight:
        return "Straight";

    case PatternValue::Flush:
        return "Flush";

    case PatternValue::FullHouse:
        return "FullHouse";

    case PatternValue::FourOfAKind:
        return "FourOfAKind";

    case PatternValue::StraightFlush:
        return "StraightFlush";

    default:
        break;
    }
};

std::string Pattern::firstValueToString(Values values) {
    switch (values) {
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

std::string Pattern::patternSuitsToString(Suits suits) {
    switch (suits) {
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
}




