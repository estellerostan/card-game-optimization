#pragma once

#include <vector>
#include <iostream>
#include "Player.h"

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
		
		// TODO: attack

		// TODO: refactor
		playerTurn = playerTurn == 0 ? 1 : 0;
		init();

		// TODO: attack
	}

	void init() {
		Player* player = _players[playerTurn];
		player->mana += 1;
		player->hand.push_back(player->deck.cards.back());
		player->deck.cards.pop_back();
	}
};