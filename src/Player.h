#pragma once

#include <vector>
#include <iostream>
#include "Deck.h"

struct Player
{
	Deck deck;

	int mana;
	int PV;
	bool isDead;
	std::vector<Card> hand;

	Player() {}
	Player(std::vector<Card> setListCards, int player) {
		deck = Deck(setListCards, player);
		mana = 0;
		PV = 20;
		isDead = false;
		for (size_t i = 0; i < 4; i++)
		{
			hand.push_back(deck.cards[rand() % deck.cards.size()]);
		}
	}
};