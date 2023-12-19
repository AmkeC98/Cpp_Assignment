#include "PlayButton.hpp"

PlayButton::PlayButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window, SceneHandler& pHandler, int& pCounter) : Button(identifier, font, buttonText, size, color), window(window), handler(pHandler), counter(pCounter)
{
}

PlayButton::~PlayButton()
{
}

void PlayButton::onClick()
{
    printf("BUTTON CLICKED - PLAY BUTTON\n");
    //Open the game scene
    if (counter == 0)
    {
        handler.stackScene("gameScene");
        counter++;
    }
    else
    {
        printf("ERROR\n");
    }

    //TODO: reset all information to start fight?
    //RESET PLAYER
    //RESET ENEMY (RANDOMIZE?)
}