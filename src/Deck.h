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
			// Not more than twice of the same card
			bool dup = true;
			while (dup) {
				Card res = setListCards[rand() % setListCards.size()];
				std::vector<Card> bar;
				std::copy_if(cards.begin(), cards.end(), std::back_inserter(bar), [res](Card c) {return c == res; });
				if (bar.size() < 2) {
					cards.push_back(res);
					dup = false;
				}
			}
		}
	}
};