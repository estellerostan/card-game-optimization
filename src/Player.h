#pragma once

#include <vector>
#include <iostream>
#include "Deck.h"

struct Player
{
	Deck deck;

	int mana;
	int PV;
	std::vector<Card> hand;

	Player() {}
	Player(std::vector<Card> setListCards, int player) {
		deck = Deck(setListCards, player);
		mana = 0;
		PV = 20;
		// TODO: random
		hand = { deck.cards.begin(), deck.cards.end() - 26 };
	}
};