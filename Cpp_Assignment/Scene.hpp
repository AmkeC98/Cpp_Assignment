#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include "GameObject.hpp"

class Scene 
{
private:
    const std::string identifier;
    std::vector<GameObject*> listOfGameObjects;

public:
    Scene(std::string identifier);
    ~Scene();

    void update();
    void render(sf::RenderWindow& window);
    void addGameObject(GameObject& object);
    std::string getIdentifier() const;
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
};