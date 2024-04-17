#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include "Deck.h"
#include "SetList.h"

Game::Game()
{
    window_.create(sf::VideoMode(1920u, 1080u), "Card game");
    window_.setFramerateLimit(60);

    sf::Clock clock;

    SetList setList;

    // std::cout << "SetList size" << setList.cards.size() << std::endl;

    auto myDeck = Deck(setList.cards, 0);
    Deck enemyDeck = Deck(setList.cards, 1);

    std::cout << "Deck size " << myDeck.cards.size() << std::endl;
    std::cout << "Deck size " << enemyDeck.cards.size() << std::endl;


}

void Game::run()
{
    while (window_.isOpen())
    {
        for (auto event = sf::Event{}; window_.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
            }
        }

        sf::Time elapsed = clock.restart();
        update(elapsed.asSeconds());
        render();
    }
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