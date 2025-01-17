#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Character.hpp"
#include "FpsCounter.hpp"
#include "QuitButton.hpp"
#include "Scene.hpp"
#include "SpriteObject.hpp"
#include "SceneHandler.hpp"
#include "TextObject.hpp"

void characterAttackItself() 
{
    // GameObject& character = scene.getGameObjectByName("character");
    //Make the character attack it self
    printf("Hello world!\n");
}

int main()
{
	std::cout << "Hello World! \n";

    sf::RenderWindow window(sf::VideoMode(400, 600), "SFML with Scenes!");

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

    Scene characterScreen("characterScreen");
    Character character("Dude", "head.png", 10, 2, 2);

    sf::Font font;
    font.loadFromFile("Lato-Regular.ttf");
    sf::Color darkColor = sf::Color(71, 82, 94, 255);
    sf::Color darkGreyColor = sf::Color(132, 146, 166, 255);
    sf::Color lightGreyColor = sf::Color(129, 144, 165, 255);

    TextObject characterName("characterNameText", font, character.getName());
    characterName.setPosition(sf::Vector2f(109.0f, 34.0f));
    characterName.setCharacterSize(26);
    characterName.setFillColor(darkColor);

    SpriteObject characterAvatar("soldierSprite", character.getSpriteFile());
    characterAvatar.setPosition(sf::Vector2f(135.0f, 90.0f));
    characterAvatar.setScale(sf::Vector2f(2.5f, 2.5f));

    TextObject hpText("hpText", font, "HP: " + std::to_string(character.getHP()));
    hpText.setPosition(sf::Vector2f(161.0f, 238.0f));
    hpText.setCharacterSize(26);
    hpText.setFillColor(darkColor);

    TextObject attackText("attackText", font, "ATTACK: " + std::to_string(character.getAttack()));
    attackText.setPosition(sf::Vector2f(148.0f, 290.0f));
    attackText.setCharacterSize(26);
    attackText.setFillColor(darkColor);

    TextObject defenseText("defenseText", font, "DEFENSE: " + std::to_string(character.getDefense()));
    defenseText.setPosition(sf::Vector2f(140.0f, 345.0f));
    defenseText.setCharacterSize(26);
    defenseText.setFillColor(darkColor);

    Button attackItselfButton("attackItselfButton", font, "ATTACK ITSELF", sf::Vector2f(192.5f, 50.0f), darkColor);
    attackItselfButton.setPosition(sf::Vector2f(108.0f, 400.0f));

    Button loadButton("loadButton", font, "LOAD", sf::Vector2f(192.5f, 50.0f), darkColor);
    loadButton.setPosition(sf::Vector2f(108.0f, 470.0f));

    QuitButton quitButton("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor, window);
    quitButton.setPosition(sf::Vector2f(108.0f, 540.0f));

    characterScreen.addGameObject(characterName);
    characterScreen.addGameObject(characterAvatar);
    characterScreen.addGameObject(hpText);
    characterScreen.addGameObject(attackText);
    characterScreen.addGameObject(defenseText);
    characterScreen.addGameObject(attackItselfButton);
    characterScreen.addGameObject(loadButton);
    characterScreen.addGameObject(quitButton);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else 
            {
                characterScreen.handleEvent(event, window);
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

        window.clear(sf::Color::White);

        fpsCounter.update(elapsed);
        fpsCounter.render(window);

        handler.update();
        handler.render(window);

        characterScreen.update();
        characterScreen.render(window);

        window.display();

        elapsed = clock.getElapsedTime();
        clock.restart();
    }

	return 0;
}