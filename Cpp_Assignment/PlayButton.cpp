#include "PlayButton.hpp"

PlayButton::PlayButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window) : Button(identifier, font, buttonText, size, color), window(window)
{
}

PlayButton::~PlayButton()
{
}

void PlayButton::onClick()
{
    printf("BUTTON CLICKED - PLAY BUTTON\n");
}