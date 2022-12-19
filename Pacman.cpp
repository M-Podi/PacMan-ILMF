//
// Created by Matei on 12/18/2022.
//

#include "Pacman.h"
void Pacman::handleMovement(std::vector<sf::RectangleShape> wall) {

    if (currentDirection != NONE) return;
    remaining = rect.getSize().x;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        currentDirection = UP;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        currentDirection = DOWN;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        currentDirection = LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        currentDirection = RIGHT;
    } else {
        currentDirection = previousDirection;
    }

    const auto next = rect.getPosition() + directions[currentDirection] * rect.getSize().x;
    if (!canMove(next,wall)) {
        if(currentDirection==previousDirection||previousDirection==NONE){
            currentDirection=NONE;
            remaining = 0;
            previousDirection=NONE;
        }
        else
            currentDirection=previousDirection;
    }
    else if(currentDirection!=NONE){
        rect.setRotation(static_cast<float>(currentDirection)*90.f-180.f);
    }
}