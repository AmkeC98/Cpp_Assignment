#include "Button.hpp"

class EraseButton : public Button
{
private:
    sf::RenderWindow& window;

public:
    EraseButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window);
    ~EraseButton();

    void onClick() override;
};