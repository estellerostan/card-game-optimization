#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include "Deck.h"
#include "SetList.h"
#include "Player.h"
#include "Turn.h"

Game::Game()
{
	//window_.create(sf::VideoMode(1920u, 1080u), "Card game");
	//window_.setFramerateLimit(60);

	sf::Clock clock;

	srand(time(NULL));

	SetList setList;
	int referenceWinRate = 0;
	std::vector<Card> referenceDeck;
	std::vector<Card> currentDeckP0;

	Player p1 = Player();
	p1.createDeck(setList.cards, 1, true);
	std::vector<Card> currentDeckP1 = p1.deck.cards;

	for (size_t j = 0; j < 250; j++)
	{
	Player p0;
	if (referenceDeck.size() > 0) {
		p0 = Player();
		p0.createDeck(referenceDeck, 0, false);
	}
	else {
		p0 = Player();
		p0.createDeck(setList.cards, 0, true);
	}
	currentDeckP0 = p0.deck.cards;

	Player p1 = Player();
	p1.createDeck(setList.cards, 1, true);
	std::vector<Card> currentDeckP1 = p1.deck.cards;

	int currentWinRate = 0;
	for (size_t i = 0; i < 1000; i++)
	{
		p0.addDeck(currentDeckP0, setList.cards);
		p0.resetPlayer();
		p1.addDeck(currentDeckP1);
		p1.resetPlayer();

		Turn turn = Turn({ &p0, &p1 });

		if (i >= 500) {
			turn.playerTurn = 1;
		}

		turn.playTurns();

		if (p1.isDead) {
			currentWinRate++;
		}
	}

	if (currentWinRate > referenceWinRate) {
		referenceWinRate = currentWinRate;
		referenceDeck = currentDeckP0;
		//std::cout << "turn " << j << ":" << std::endl;
		std::cout << "WR: " << currentWinRate / 10.f << "%" << std::endl << std::endl;
	}

	std::cout << "WR P1: " << currentWinRate / 10.f << "% vs P2: " << (1000 - currentWinRate) / 10.F << "%" << std::endl;
//}

	for each (Card card in referenceDeck)
	{
		std::cout << card << std::endl;
	}
	auto elapsed = clock.getElapsedTime();
	std::cout << "Time taken: " << elapsed.asMilliseconds() << " ms" << std::endl;
}

void Game::run()
{
	//while (window_.isOpen())
	//{
	//	for (auto event = sf::Event{}; window_.pollEvent(event);)
	//	{
	//		if (event.type == sf::Event::Closed)
	//		{
	//			window_.close();
	//		}
	//	}

	//	sf::Time elapsed = clock.restart();
	//	update(elapsed.asSeconds());
	//	render();
	//}
}

void Game::update(float deltaTime)
{
	// TODO:
}

void Game::render()
{
	window_.clear();
	// TODO:
	// window.draw();
	window_.display();
}