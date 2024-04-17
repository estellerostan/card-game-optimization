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

	int winRate = 0;
	for (size_t i = 0; i < 1000; i++)
	{
		Player p0 = Player(setList.cards, 0);
		Player p1 = Player(setList.cards, 1);

		Turn turn = Turn({ &p0, &p1 });

		if (i >= 500) {
			turn.playerTurn = 1;
		}

		turn.playTurns();

		if (p1.isDead) {
			winRate++;
		}
	}

	std::cout << "WR P1: " << winRate / 10.f << "% vs P2: " << (1000 - winRate) / 10.F << "%" << std::endl;
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