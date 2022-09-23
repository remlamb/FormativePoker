#pragma once
#include <string> 

enum class Values {
    deux,
    trois,
    quatre,
    cinq,
    six,
    sept,
    huit,
    neuf,
    dix,
    Jack,
    Queen,
    King,
    As,
};

enum class Suits {
    Spades,
    Clubs,
    Hearts,
    Diamonds,
};

class Card
{
    private: 
        

    public:

        Values _theValues;
        Suits _theSuits;
        
        std::string suitsToString();
        std::string valuesToString();

        Card(Values theValues, Suits theSuits);

        void readACard();

        static bool compareCardValues(Card a, Card b);

};

