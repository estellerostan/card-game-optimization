#pragma once

#include <SFML/Graphics.hpp>

class Game
{
    sf::RenderWindow window_;

    sf::Clock clock;

    std::vector<int> winRates;
    sf::Vertex line[1000];

    void update(float deltaTime);
    void render();

public:
    Game();
    void run();
};