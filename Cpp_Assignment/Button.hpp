#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "GameObject.hpp"
#include "Scene.hpp"

class Button : public GameObject 
{
private:
    sf::Text text;
    sf::Font& font;
    sf::RectangleShape shape;
    std::string buttonText;

public:
    Button(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color);
    ~Button();

    void update() override;
    void render(sf::RenderWindow& window) override;
    void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
    virtual void onClick();
    void setCharacterSize(const int size);
    void setPosition(const sf::Vector2f position);
};