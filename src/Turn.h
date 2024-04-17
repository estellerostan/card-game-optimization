#pragma once

#include <vector>
#include <iostream>
#include "Player.h"
#include "Card.h"

struct Turn
{
	std::vector<Player*> _players;
	int playerTurn;

	Turn() {};
	Turn(std::vector<Player*> players) {
		_players = players;
		// TODO: 500 games each
		playerTurn = 0;
	}

	void playTurn() {
		init();
		attack();

		// TODO: refactor
		playerTurn = playerTurn == 0 ? 1 : 0;
		init();
		attack();
	}

	void init() {
		Player* player = _players[playerTurn];
		player->mana += 1;
		player->hand.push_back(player->deck.cards.back());
		player->deck.cards.pop_back();
	}

	void attack() {
		Player* player = _players[playerTurn];
		Card& cardToPlay = Card(-1, -1);

		while (canAttack(cardToPlay)) {
			player->mana -= cardToPlay.Cost;
			player->hand.erase(std::find(player->hand.begin(), player->hand.end(), cardToPlay));
			Player* enemy = _players[playerTurn == 0 ? 1 : 0];
			enemy->PV -= cardToPlay.ATK;
			cardToPlay = Card(-1, -1);
		}
	}

	bool canAttack(Card& cardToPlay)
	{
		Player* player = _players[playerTurn];

		for each (auto current in player->hand)
		{
			if (current.Cost > cardToPlay.Cost && current.Cost <= player->mana)
			{
				cardToPlay = current;
			}
		}

		if (cardToPlay.Cost != -1) {
			return true;
		}

		return false;
	}
};