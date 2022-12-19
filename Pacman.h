//
// Created by Matei on 12/18/2022.
//

#ifndef OOP_PACMAN_H
#define OOP_PACMAN_H
#include "Entity.h"

class Pacman:public Entity {
public:
    Pacman()=default;
    Pacman(float x, float y):Entity(x,y){};
    void handleMovement(std::vector<sf::RectangleShape> wall) override;
};


#endif //OOP_PACMAN_H
