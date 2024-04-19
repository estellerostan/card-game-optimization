#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <fstream>
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
	std::vector<Card> currentDeckP0;

	Player p1 = Player();
	p1.createDeck(setList.cards, 1, true);
	std::vector<Card> currentDeckP1 = p1.deck.cards;

	for (size_t j = 0; j < 500; j++)
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
		p0.addDeck(currentDeckP0, setList.cards);
		currentDeckP0.clear();
		std::copy(p0.deck.cards.begin(), p0.deck.cards.end(), std::back_inserter(currentDeckP0));

		int currentWinRate = 0;
		for (size_t i = 0; i < 1000; i++)
		{
			p0.deck.cards = currentDeckP0;
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

			turnsCount[turn.turnsCount] += 1;
		}

		if (currentWinRate > referenceWinRate) {
			referenceWinRate = currentWinRate;
			referenceDeck = currentDeckP0;
			//std::cout << "turn " << j << ":" << std::endl;
			//std::cout << "WR: " << currentWinRate / 10.f << "%" << std::endl << std::endl;
			winRates.push_back(currentWinRate);
		}

		//std::cout << "WR P1: " << currentWinRate / 10.f << "% vs P2: " << (1000 - currentWinRate) / 10.F << "%" << std::endl;
	}

	for each (Card card in referenceDeck)
	{
		std::cout << card << std::endl;
	}
	auto elapsed = clock.getElapsedTime();
	std::cout << "Time taken: " << elapsed.asMilliseconds() << " ms" << std::endl;

	std::ofstream myfile;
	myfile.open("example.csv");
	myfile << "Win rate.\n";
	myfile << "nbGames, WR,\n";
	int i = 0;
	for each (int var in winRates)
	{
		i++;
		myfile << i << "," << var / 10.f << "\n";
	}
	myfile.close();

	for each (Card var in referenceDeck)
	{
		costDeck[var.Cost] += 1;
	}

	std::ofstream myfile2;
	myfile2.open("example2.csv");
	myfile2 << "Meilleures cartes.\n";
	myfile2 << "cout, effectif,\n";
	int j = 0;
	for each (auto var in costDeck)
	{
		myfile2 << var.first << "," << var.second << "\n";
		j++;
	}

	std::ofstream myfile3;
	myfile3.open("example3.csv");
	myfile3 << "Durée des parties.\n";
	myfile3 << "tours, effectif,\n";
	int h = 0;
	for each (auto var in turnsCount)
	{
		myfile3 << var.first << "," << var.second << "\n";
		h++;
	}
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
	//window_.clear();
	//int i = 0;
	//for each (int var in winRates)
	//{
	//	line[i] = sf::Vertex(sf::Vector2f(i * 2, var * 2));
	//	i++;
	//}

	//int j = 0;
	//for each (auto var in costDeck)
	//{
	//	//costLine[j] = sf::Vertex(sf::Vector2f(var.first * 10, var.second * 10));
	//	sf::RectangleShape rectangle(sf::Vector2f(var.first * j, var.second * j));
	//	window_.draw(rectangle);
	//	j++;
	//}

	//window_.draw(line, 1000, sf::Lines);
	//window_.draw(costLine, 1000, sf::Lines);
	//window_.display();
}