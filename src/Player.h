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
	Player(std::vector<Card> cards, int player, bool randomDeck, std::vector<Card> setListCards = {}) {
		if (randomDeck) {
			deck = Deck(cards, player);
		}
		else {
			deck.cards = cards;
			// Not more than twice of the same card
			bool dup = true;
			while (dup) {
				Card randomCard = setListCards[rand() % setListCards.size()];
				Card res = deck.cards[rand() % deck.cards.size()];
				std::vector<Card> bar;
				std::copy_if(cards.begin(), cards.end(), std::back_inserter(bar), [randomCard](Card c) {return c == randomCard; });
				if (bar.size() < 2) {
					deck.cards.erase(std::find(deck.cards.begin(), deck.cards.end(), res));
					deck.cards.push_back(randomCard);
					dup = false;
				}
				else {
					dup = true;
				}
			}			
		}
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