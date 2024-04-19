#pragma once

#include <cmath>
#include <ostream>
#include <vector>
#include "Card.h"

struct Board
{
	std::vector<Card> cards;

	Board() {

	}

	void add(Card card) {
		cards.push_back(card);
	}

	void playCards(Player* enemy) {
		for each (Card card in cards)
		{
			enemy->PV = std::max(enemy->PV - card.ATK, 0);

			if (enemy->PV == 0) {
				enemy->isDead = true;
				return;
			}
		}
	}
};