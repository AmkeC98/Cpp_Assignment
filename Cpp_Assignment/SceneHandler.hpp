#pragma once

#include <map>
#include <stack>
#include "scene.hpp"

class SceneHandler 
{
private:
    std::map<std::string, Scene*> scenes;
    std::stack<Scene*> scenesStack;

public:
    SceneHandler();
    ~SceneHandler();

    void update();
    void render(sf::RenderWindow& window) const;
    void addScene(Scene& scene);
    void stackScene(std::string sceneName);
    void popScene();
};