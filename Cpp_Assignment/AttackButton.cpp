#include "AttackButton.hpp"

AttackButton::AttackButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window) : Button(identifier, font, buttonText, size, color), window(window)
{
}

AttackButton::~AttackButton()
{
}

void AttackButton::onClick()
{
    printf("BUTTON CLICKED - ATTACK BUTTON\n");
}