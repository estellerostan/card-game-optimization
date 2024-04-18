#pragma once

#include <SFML/Graphics.hpp>
#include "Card.h"

class Game
{
    sf::RenderWindow window_;

    sf::Clock clock;

    std::vector<int> winRates;
    sf::Vertex line[1000];

    std::vector<Card> referenceDeck;
    std::map<int, int> costDeck;
    std::map<int, int> turnsCount;

    void update(float deltaTime);
    void render();

public:
    Game();
    void run();
};