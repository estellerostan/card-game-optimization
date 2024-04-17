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
			Card res = deck.cards[rand() % deck.cards.size()];
			hand.push_back(res);
			deck.cards.erase(std::find(deck.cards.begin(), deck.cards.end(), res));
		}
	}
};