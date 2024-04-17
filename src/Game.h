#include <SFML/Graphics.hpp>

class Game
{
    sf::RenderWindow window_;

    sf::Clock clock;

    void update(float deltaTime);
    void render();

public:
    Game();
    void run();
};