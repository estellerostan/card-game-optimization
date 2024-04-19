#include <vector>
#include <iostream>
#include "Card.h"

struct SetList
{
	std::vector<Card> cards;
    int cardMaxCost = 8;

	SetList() {
        for (int atk = 0; atk <= cardMaxCost * 2; atk++)
        {
            for (int def = 1; def <= cardMaxCost * 2; def++)
            {
                for (int taunt = 0; taunt <= 1; taunt++)
                {
                    for (int trample = 0; trample <= 1; trample++)
                    {
                        for (int distortion = 0; distortion <= 1; distortion++)
                        {
                            for (int firstStrike = 0; firstStrike <= 1; firstStrike++)
                            {
                                Card card = Card(atk, def, taunt == 1, trample == 1, distortion == 1, firstStrike == 1);

                                if (card.Cost <= cardMaxCost)
                                {
                                    cards.push_back(card);
                                }
                            }
                        }
                    }
                }
            }
        }
	}
};