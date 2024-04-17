#pragma once

#include <vector>
#include <iostream>
#include "Card.h"

struct Deck
{
	std::vector<Card> cards;

	Deck(std::vector<Card> setListCards, int player) {
		if (player == 0) {
			cards = { setListCards.begin(), setListCards.end() - 60 };
		}
		else if (player == 1) {
			cards = { setListCards.begin() + 30, setListCards.end() - 30 };
		}
	}
};