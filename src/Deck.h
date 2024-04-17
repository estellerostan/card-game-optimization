#pragma once

#include <vector>
#include <iostream>
#include "Card.h"
#include <algorithm>

struct Deck
{
	std::vector<Card> cards;

	Deck() {};
	Deck(std::vector<Card> setListCards, int player) {
		for (size_t i = 0; i < 30; i++)
		{
			// TODO: not more than twice of the same card
			cards.push_back(setListCards[rand() % setListCards.size()]);
		}
	}
};