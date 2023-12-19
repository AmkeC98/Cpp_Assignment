#include "Button.hpp"
#include "SceneHandler.hpp"

class MenuButton : public Button
{
private:
    sf::RenderWindow& window;
    SceneHandler& handler;
    int& counter;

public:
    MenuButton(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color, sf::RenderWindow& window, SceneHandler& pHandler, int& pCounter);
    ~MenuButton();

    void onClick() override;
};