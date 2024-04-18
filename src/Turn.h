#pragma once

#include <vector>
#include <iostream>
#include "Player.h"
#include "Card.h"

struct Turn
{
	std::vector<Player*> _players;
	int playerTurn;
	int turnsCount = 0;

	Turn() {};
	Turn(std::vector<Player*> players) {
		_players = players;
		playerTurn = 0;
	}

	void playTurns() {
		while ((!_players[0]->isDead && !_players[1]->isDead))
		{
			playTurn();
			turnsCount++;
		}
	}

	void playTurn() {
		init();
		attack();

		// TODO: refactor
		playerTurn = playerTurn == 0 ? 1 : 0;

		if (_players[playerTurn]->isDead) {
			return;
		}

		init();
		attack();
	}

	void init() {
		Player* player = _players[playerTurn];
		player->mana += 1;
		if (player->deck.cards.size() > 0) {
			Card res = player->deck.cards[rand() % player->deck.cards.size()];
			player->hand.push_back(res);
			player->deck.cards.erase(std::find(player->deck.cards.begin(), player->deck.cards.end(), res));
		}
	}

	void attack() {
		Player* player = _players[playerTurn];
		Card& cardToPlay = Card(-1, -1);

		while (canAttack(cardToPlay)) {
			player->mana -= cardToPlay.Cost;
			player->hand.erase(std::find(player->hand.begin(), player->hand.end(), cardToPlay));
			Player* enemy = _players[playerTurn == 0 ? 1 : 0];
			enemy->PV = std::max(enemy->PV - cardToPlay.ATK, 0);

			if (enemy->PV == 0) {
				enemy->isDead = true;
				return;
			}

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