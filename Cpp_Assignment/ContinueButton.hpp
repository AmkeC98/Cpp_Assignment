#include "Button.hpp"

class ContinueButton : public Button
{
private:
    sf::RenderWindow& window;

public:
    ContinueButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window);
    ~ContinueButton();

    void onClick() override;
};