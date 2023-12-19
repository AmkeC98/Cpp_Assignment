#include "MenuButton.hpp"

MenuButton::MenuButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window, SceneHandler& pHandler, int& pCounter) : Button(identifier, font, buttonText, size, color), window(window), handler(pHandler), counter(pCounter)
{
}

MenuButton::~MenuButton()
{
}

void MenuButton::onClick()
{
    printf("BUTTON CLICKED - MENU BUTTON\n");

    //Open the game scene
    if (counter == 1)
    {
        handler.popScene();
        counter--;
    }
    else
    {
        printf("ERROR\n");
    }
}