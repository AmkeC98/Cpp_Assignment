#include "QuitButton.hpp"

QuitButton::QuitButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window) : Button(identifier, font, buttonText, size, color), window(window) 
{ 
}

QuitButton::~QuitButton() 
{ 
}

void QuitButton::onClick() 
{
    printf("BUTTON CLICKED - QUIT BUTTON\n");
    //this->window.close();
}