#include "ContinueButton.hpp"

ContinueButton::ContinueButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window) : Button(identifier, font, buttonText, size, color), window(window)
{
}

ContinueButton::~ContinueButton()
{
}

void ContinueButton::onClick()
{
    printf("BUTTON CLICKED - CONTINUE BUTTON\n");
}