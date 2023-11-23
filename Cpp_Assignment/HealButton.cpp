#include "HealButton.hpp"

HealButton::HealButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window) : Button(identifier, font, buttonText, size, color), window(window)
{
}

HealButton::~HealButton()
{
}

void HealButton::onClick()
{
    printf("BUTTON CLICKED - HEAL BUTTON\n");
}