#include <iostream>
#include <SFML/Graphics.hpp>
#include "FpsCounter.hpp"
#include "Scene.hpp"
#include "SpriteObject.hpp"
#include "SceneHandler.hpp"

int main()
{
	std::cout << "Hello World! \n";

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML with Scenes!");

    FPSCounter fpsCounter;

    sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();

    Scene scene1("scene01");

    SpriteObject sprite1("soldierSprite", "head.png");
    sprite1.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite1.setScale(sf::Vector2f(5.0f, 5.0f));
    scene1.addGameObject(sprite1);

    Scene scene2("scene02");

    SpriteObject sprite2("soldierSprite", "head_hurt.png");
    sprite2.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite2.setScale(sf::Vector2f(5.0f, 5.0f));
    scene2.addGameObject(sprite2);

    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);

    int counter = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) 
            {
                if (event.key.code == sf::Keyboard::A) 
                {
                    if (counter == 0) 
                    {
                        handler.stackScene("scene02");
                        counter++;
                    }
                    else 
                    {
                        handler.popScene();
                        counter--;
                    }
                }
            }
        }

        window.clear();

        fpsCounter.update(elapsed);
        fpsCounter.render(window);

        handler.update();
        handler.render(window);

        window.display();

        elapsed = clock.getElapsedTime();
        clock.restart();
    }

	return 0;
}