#pragma once
#include "Card.h"
#include<vector>


struct Pattern
{
	enum class PatternValue {
		Highcard,
		Pair,
		TwoPairs,
		ThreeOfAKind,
		Straight,
		Flush,
		FullHouse,
		FourOfAKind,
		StraightFlush,
	};

	Values firstValue;
	Values secondValue;
	Values thirdValue;

	Suits Suit;


	PatternValue PatternValue;


	std::string patternToString();

	std::string firstValueToString(Values);
	std::string patternSuitsToString(Suits);

}; 
