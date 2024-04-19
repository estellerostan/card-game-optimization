#pragma once

#include <vector>
#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Board.h"

struct Turn
{
	std::vector<Player*> _players;
	int playerTurn;
	int turnsCount = 0;
	std::vector<Board> boards;

	Turn() {};
	Turn(std::vector<Player*> players) {
		_players = players;
		playerTurn = 0;	
		boards.push_back(Board());
		boards.push_back(Board());
	}

	void playTurns() {
		while ((!_players[0]->isDead && !_players[1]->isDead))
		{
			playTurn();
			turnsCount++;
		}
	}

	void playTurn() {
		if (_players[playerTurn]->isDead) {
			return;
		}

		init();
		attack();

		// TODO: refactor
		playerTurn = playerTurn == 0 ? 1 : 0;	
	}

	void init() {
		Player* player = _players[playerTurn];
		player->mana += 1;
		// draw 1 card if possible
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
			boards[playerTurn].add(cardToPlay);

			cardToPlay = Card(-1, -1);
		}
		Player* enemy = _players[playerTurn == 0 ? 1 : 0];
		boards[playerTurn].playCards(enemy);
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