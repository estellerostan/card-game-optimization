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

	void playCards(Player* enemy, Board enemyBoard) {
		std::vector<Card*> enemyCards;

		for each (Card c in enemyBoard.cards)
		{
			if (c.hasTaunt) {
				enemyCards.push_back(new Card(c.ATK, c.DEF, c.hasTaunt, c.hasTrample, c.hasDistortion, c.hasFirstStrike));
			}
		}

		std::vector<Card*> myCards;
		for each (Card c in cards)
		{
			if (c.ATK > 0) {
				myCards.push_back(new Card(c.ATK, c.DEF, c.hasTaunt, c.hasTrample, c.hasDistortion, c.hasFirstStrike));
			}
		}

		for each (Card * card in myCards)
		{
			auto canDefend = [](Card * c) { return c->DEF > 0; };
			if (auto it = std::find_if(std::begin(enemyCards), std::end(enemyCards), canDefend); it != std::end(enemyCards)) {
				// taunt
				for each (Card * enemyCard in enemyCards)
				{
					// attack enemy
					if (enemyCard->DEF > 0) {
						enemyCard->DEF -= card->ATK;
					}

					if (enemyCard->ATK == 0) {
						continue;
					}

					// enemy attacks back
					if (enemyCard->DEF > 0) {
						if (card->DEF > 0) {
							card->DEF -= enemyCard->ATK;
						}
					}

					// only attack once
					break;
				}
			}
			else {
				enemy->PV = std::max(enemy->PV - card->ATK, 0);

				if (enemy->PV == 0) {
					enemy->isDead = true;
					return;
				}
			}
		}
	}
};