#include "Button.hpp"

class MenuButton : public Button
{
private:
    sf::RenderWindow& window;

public:
    MenuButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window);
    ~MenuButton();

    void onClick() override;
};