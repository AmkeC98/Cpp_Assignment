#include "MenuButton.hpp"

MenuButton::MenuButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window) : Button(identifier, font, buttonText, size, color), window(window)
{
}

MenuButton::~MenuButton()
{
}

void MenuButton::onClick()
{
    printf("BUTTON CLICKED - MENU BUTTON\n");
}