#include "Button.hpp"

class AttackButton : public Button
{
private:
    sf::RenderWindow& window;

public:
    AttackButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window);
    ~AttackButton();

    void onClick() override;
};