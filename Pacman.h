//
// Created by Matei on 12/18/2022.
//

#ifndef OOP_PACMAN_H
#define OOP_PACMAN_H
#include "Entity.h"
#include "Ghosts.h"

class Pacman:public Entity {
public:
    Pacman()=default;
    Pacman(float x, float y):Entity(x,y,Resources::Pac,4){};
    void handleMovement(const std::vector<std::string> &map_sketch,sf::Vector2f relPos) override;

    Entity* clone() const override { return new Pacman(*this); }
};


#endif //OOP_PACMAN_H
