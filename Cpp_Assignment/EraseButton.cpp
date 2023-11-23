#include "EraseButton.hpp"

EraseButton::EraseButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window) : Button(identifier, font, buttonText, size, color), window(window)
{
}

EraseButton::~EraseButton()
{
}

void EraseButton::onClick()
{
    printf("BUTTON CLICKED - ERASE BUTTON\n");
}