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
    Entity(float x, float y,sf::Texture &texture,int frames);
    virtual ~Entity()=default;
    void setPosition(sf::Vector2f Pos);
    void drawTo(sf::RenderWindow &window);
    virtual void handleMovement(const std::vector<std::string> &map_sketch,sf::Vector2f relPos)=0;
    static bool canMove(const sf::Vector2<float>& move,const std::vector<std::string> &map_sketch);
    void move(const std::vector<std::string> &map_sketch,int screenSize);
    void update2(float deltaTime);
    sf::Rect<float> GetGlobalBounds();
    sf::Vector2f GetPosition();
    virtual Entity* clone() const = 0;
    //virtual void setScared(bool Scared) {return; };
protected:
    Animation animation2;
    sf::RectangleShape rect;
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
