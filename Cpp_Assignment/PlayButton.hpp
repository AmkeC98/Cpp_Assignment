#include "Button.hpp"

class PlayButton : public Button
{
private:
    sf::RenderWindow& window;

public:
    PlayButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window);
    ~PlayButton();

    void onClick() override;
};