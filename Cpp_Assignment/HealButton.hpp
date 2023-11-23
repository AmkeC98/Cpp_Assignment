#include "Button.hpp"

class HealButton : public Button
{
private:
    sf::RenderWindow& window;

public:
    HealButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window);
    ~HealButton();

    void onClick() override;
};