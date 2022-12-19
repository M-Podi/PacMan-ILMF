#pragma once
#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Animation.h"
#include "Resources.h"
#include "Map.h"
namespace directions
{
    enum options
    {
        Up,
        Down,
        Left,
        Right,
        None
    };
}
class Entity {
public:
    Entity();
    Entity(float x, float y);
    void Innit(float x, float y);
    void setPosition(sf::Vector2f Pos);
    void drawTo(sf::RenderWindow &window);
    virtual void handleMovement(std::vector<sf::RectangleShape> wall)=0;
    bool canMove(const sf::Vector2<float>& move,const std::vector<sf::RectangleShape> &wall);
    void move(std::vector<sf::CircleShape>& point,std::vector<sf::CircleShape>& powerup,std::vector<std::string> map_sketch,int screenSize);
    void update2(float deltaTime);
protected:
    Animation animation2;
    sf::RectangleShape rect;
    sf::Vector2f prevpos;
    const sf::Vector2f directions[5] = {
            {-1, 0},
            {0, -1},
            {1, 0},
            {0, 1},
            {0, 0}
    };
    enum MOVE {
        LEFT, UP, RIGHT, DOWN, NONE
    };

    float speed= 3.0f;
    float remaining = 0;

    MOVE currentDirection = NONE;
    MOVE previousDirection = NONE;
    directions::options direction=directions::None;
};


#endif //OOP_ENTITY_H
