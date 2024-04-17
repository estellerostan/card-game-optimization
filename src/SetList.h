#include <vector>
#include <iostream>
#include "Card.h"

struct SetList
{
	std::vector<Card> cards;

	SetList() {
		for (int atk = 0; atk <= 12; atk++)
		{
			for (int def = 1; def <= 12; def++)
			{
				Card card = Card(atk, def);
				if (card.Cost <= 6)
				{
					//std::cout << card << std::endl;
					cards.push_back(card);
				}
			}
		}
	}
};