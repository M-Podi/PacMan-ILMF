//
// Created by Matei on 12/21/2022.
//

#ifndef OOP_GHOSTS_H
#define OOP_GHOSTS_H
#include "Entity.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
class Ghosts:public Entity {
public:
    Ghosts()=default;
    Ghosts(float x, float y,sf::Texture &color):Entity(x,y,color,2){};
    void handleMovement(const std::vector<std::string> &map_sketch,sf::Vector2f relPos) override;
    Entity* clone() const override { return new Ghosts(*this); }
};

#endif //OOP_GHOSTS_H
