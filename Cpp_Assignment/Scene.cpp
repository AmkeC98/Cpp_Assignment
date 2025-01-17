#include "Scene.hpp"

Scene::Scene(std::string identifier) : identifier(identifier) 
{ 
}

Scene::~Scene() 
{ 
}

void Scene::update() 
{
    for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++) 
    {
        this->listOfGameObjects[i]->update();
    }
}

void Scene::render(sf::RenderWindow& window) 
{
    for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++) 
    {
        this->listOfGameObjects[i]->render(window);
    }
}

void Scene::addGameObject(GameObject& object)
{
    this->listOfGameObjects.push_back(&object);
}

std::string Scene::getIdentifier() const 
{
    return this->identifier;
}

void Scene::handleEvent(const sf::Event& event, sf::RenderWindow& window) 
{
    for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++) 
    {
        this->listOfGameObjects[i]->handleEvent(event, window);
    }
}