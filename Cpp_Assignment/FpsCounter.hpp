#pragma once

#include <SFML/Graphics.hpp>

class FPSCounter 
{
private:
    sf::Text text;
    sf::Font font;

public:
    FPSCounter();
    ~FPSCounter();

    void update(sf::Time elapsed);
    void render(sf::RenderWindow& window);
};