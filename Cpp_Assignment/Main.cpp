#include <iostream>
#include <SFML/Graphics.hpp>
#include "FpsCounter.hpp"

int main()
{
	std::cout << "Hello World! \n";

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    FPSCounter fpsCounter;

    sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        fpsCounter.update(elapsed);
        fpsCounter.render(window);

        window.display();

        elapsed = clock.getElapsedTime();
        clock.restart();
    }

	return 0;
}