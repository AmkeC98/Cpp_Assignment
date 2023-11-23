#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AttackButton.hpp"
#include "Button.hpp"
#include "Character.hpp"
#include "ContinueButton.hpp"
#include "EraseButton.hpp"
#include "FpsCounter.hpp"
#include "HealButton.hpp"
#include "MenuButton.hpp"
#include "PlayButton.hpp"
#include "QuitButton.hpp"
#include "Scene.hpp"
#include "SceneHandler.hpp"
#include "SpriteObject.hpp"
#include "TextObject.hpp"

int main()
{
    // ---------- GENERAL SETUP ---------- //

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Cpp Assignment '23-'24");

    FPSCounter fpsCounter;

    sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();

    sf::Font font;
    font.loadFromFile("Arial.ttf");

    sf::Color darkColor = sf::Color(71, 82, 94, 255);
    sf::Color darkGreyColor = sf::Color(132, 146, 166, 255);
    sf::Color lightGreyColor = sf::Color(129, 144, 165, 255);

    int characterSize = 26;

    int counter = 0;

    //Create the main menu scene
    Scene menuScene("menuScene");
    //Create the fight game scene
    Scene gameScene("gameScene");

    SceneHandler handler;
    handler.addScene(menuScene);
    handler.addScene(gameScene);


    // ---------- MENU SETUP ---------- //

    //Add the Play Game button
    PlayButton playButton("playButton", font, "PLAY", sf::Vector2f(192.5f, 50.0f), darkColor, window);
    playButton.setPosition(sf::Vector2f(942.0f, 235.0f));
    playButton.setCharacterSize(characterSize);

    //Add the Erase Data button
    EraseButton eraseButton("eraseButton", font, "ERASE", sf::Vector2f(192.5f, 50.0f), darkColor, window);
    eraseButton.setPosition(sf::Vector2f(942.0f, 335.0f));
    eraseButton.setCharacterSize(characterSize);

    //Add the Quit Game button
    QuitButton quitButton("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor, window);
    quitButton.setPosition(sf::Vector2f(942.0f, 435.0f));
    quitButton.setCharacterSize(characterSize);

    //Add the Rankings text
    TextObject rankingsText("rankingsText", font, "PLACEHOLDER TEXT");
    rankingsText.setPosition(sf::Vector2f(200.0f, 235.0f));
    rankingsText.setCharacterSize(characterSize);
    rankingsText.setFillColor(darkColor);

    //Add all to the scene
    menuScene.addGameObject(playButton);
    menuScene.addGameObject(eraseButton);
    menuScene.addGameObject(quitButton);
    menuScene.addGameObject(rankingsText);

    // ---------- GAME SETUP ---------- //

    //Add the Attack button
    AttackButton attackButton("attackButton", font, "ATTACK", sf::Vector2f(192.5f, 50.0f), darkColor, window);
    attackButton.setPosition(sf::Vector2f(400.0f, 540.0f));
    attackButton.setCharacterSize(characterSize);

    //Add the Heal button
    HealButton healButton("healButton", font, "HEAL", sf::Vector2f(192.5f, 50.0f), darkColor, window);
    healButton.setPosition(sf::Vector2f(700.0f, 540.0f));
    healButton.setCharacterSize(characterSize);

    //Add the Continue button
    ContinueButton continueButton("continueButton", font, "CONTINUE", sf::Vector2f(192.5f, 50.0f), darkColor, window);
    continueButton.setPosition(sf::Vector2f(700.0f, 620.0f));
    continueButton.setCharacterSize(characterSize);

    //Add the Menu button
    MenuButton menuButton("menuButton", font, "MENU", sf::Vector2f(192.5f, 50.0f), darkColor, window);
    menuButton.setPosition(sf::Vector2f(400.0f, 620.0f));
    menuButton.setCharacterSize(characterSize);

    //Add the results text
    TextObject resultsText("resultsText", font, "PLACEHOLDER TEXT");
    resultsText.setPosition(sf::Vector2f(400.0f, 400.0f));
    resultsText.setCharacterSize(characterSize);
    resultsText.setFillColor(darkColor);

    //Add the player
    //Create the player character
    Character player("player", "head.png", 10, 3, 3);

    //Add the player sprite
    SpriteObject playerSprite("playerSprite", player.getSpriteFile());
    playerSprite.setPosition(sf::Vector2f(250.0f, 100.0f));
    playerSprite.setScale(sf::Vector2f(1.0f, 1.0f));

    //Add the player name text
    TextObject playerNameText("playerNameText", font, "NAME: X");
    playerNameText.setPosition(sf::Vector2f(250.0f, 200.0f));
    playerNameText.setCharacterSize(characterSize);
    playerNameText.setFillColor(darkColor);

    //Add the player hp text
    TextObject playerHpText("playerHpText", font, "HP: 0");
    playerHpText.setPosition(sf::Vector2f(250.0f, 230.0f));
    playerHpText.setCharacterSize(characterSize);
    playerHpText.setFillColor(darkColor);

    //Add the player att text
    TextObject playerAttText("playerAttText", font, "ATT: 0");
    playerAttText.setPosition(sf::Vector2f(250.0f, 260.0f));
    playerAttText.setCharacterSize(characterSize);
    playerAttText.setFillColor(darkColor);

    //Add the player def text
    TextObject playerDefText("playerDefText", font, "DEF: 0");
    playerDefText.setPosition(sf::Vector2f(250.0f, 290.0f));
    playerDefText.setCharacterSize(characterSize);
    playerDefText.setFillColor(darkColor);

    //Add the enemy
    //Create the enemy character
    Character enemy("enemy", "head_hurt.png", 10, 2, 2);

    //Add the enemy sprite
    SpriteObject enemySprite("enemySprite", enemy.getSpriteFile());
    enemySprite.setPosition(sf::Vector2f(929.0f, 100.0f));
    enemySprite.setScale(sf::Vector2f(1.0f, 1.0f));

    //Add the enemy name text
    TextObject enemyNameText("enemyNameText", font, "NAME: X");
    enemyNameText.setPosition(sf::Vector2f(929.0f, 200.0f));
    enemyNameText.setCharacterSize(characterSize);
    enemyNameText.setFillColor(darkColor);

    //Add the enemy hp text
    TextObject enemyHpText("enemyHpText", font, "HP: 0");
    enemyHpText.setPosition(sf::Vector2f(929.0f, 230.0f));
    enemyHpText.setCharacterSize(characterSize);
    enemyHpText.setFillColor(darkColor);

    //Add the enemy att text
    TextObject enemyAttText("enemyAttText", font, "ATT: 0");
    enemyAttText.setPosition(sf::Vector2f(929.0f, 260.0f));
    enemyAttText.setCharacterSize(characterSize);
    enemyAttText.setFillColor(darkColor);

    //Add the enemy def text
    TextObject enemyDefText("enemyDefText", font, "DEF: 0");
    enemyDefText.setPosition(sf::Vector2f(929.0f, 290.0f));
    enemyDefText.setCharacterSize(characterSize);
    enemyDefText.setFillColor(darkColor);

    //Add all to the scene
    gameScene.addGameObject(attackButton);
    gameScene.addGameObject(healButton);
    gameScene.addGameObject(continueButton);
    gameScene.addGameObject(menuButton);
    gameScene.addGameObject(resultsText);
    gameScene.addGameObject(playerSprite);
    gameScene.addGameObject(playerNameText);
    gameScene.addGameObject(playerHpText);
    gameScene.addGameObject(playerAttText);
    gameScene.addGameObject(playerDefText);
    gameScene.addGameObject(enemySprite);
    gameScene.addGameObject(enemyNameText);
    gameScene.addGameObject(enemyHpText);
    gameScene.addGameObject(enemyAttText);
    gameScene.addGameObject(enemyDefText);


    // ---------- GAME LOOP ---------- //

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
                menuScene.handleEvent(event, window);
                gameScene.handleEvent(event, window);
            }
            
            if (event.type == sf::Event::KeyReleased) 
            {
                if (event.key.code == sf::Keyboard::A) 
                {
                    if (counter == 0) 
                    {
                        handler.stackScene("gameScene");
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

        window.display();

        elapsed = clock.getElapsedTime();
        clock.restart();
    }

	return 0;
}