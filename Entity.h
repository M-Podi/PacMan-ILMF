#pragma once
#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Animation.h"
#include "Resources.h"
class Entity {
public:
    Entity();
    Entity(float x, float y);
    void Innit(float x, float y);
    void setPosition(sf::Vector2f Pos);
    void processEvents(sf::Keyboard::Key key, bool checkPressed);
    void update(float deltaTime,std::vector<sf::RectangleShape> wall);
    void drawTo(sf::RenderWindow &window);
private:
    Animation animation2;
    sf::RectangleShape rect;
    sf::Vector2f lastPos;
    bool up, down, left, right;
};


#endif //OOP_ENTITY_H
