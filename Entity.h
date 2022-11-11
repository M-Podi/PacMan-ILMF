//
// Created by Matei on 11/9/2022.
//

#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include "SFML/Graphics.hpp"

class Entity {
public:
    Entity(float x,float y) {
        rect.setSize(sf::Vector2f(x, y));
        up = false;
        down = false;
        left = false;
        right = false;
    }
    void processEvents(sf::Keyboard::Key key, bool checkPressed) {
        if (checkPressed == true) {
            if (key == sf::Keyboard::Up || key == sf::Keyboard::W)
                up = true;
            if (key == sf::Keyboard::Down || key == sf::Keyboard::S)
                down = true;
            if (key == sf::Keyboard::Left || key == sf::Keyboard::A)
                left = true;
            if (key == sf::Keyboard::Right || key == sf::Keyboard::D)
                right = true;
        }
        else {
            up = false;
            down = false;
            left = false;
            right = false;
        }
    }
    void update() {
        sf::Vector2f movement;
        if (up)
            movement.y -= 0.3f;
        if (down)
            movement.y += 0.3f;
        if (left)
            movement.x -= 0.3f;
        if (right)
            movement.x += 0.3f;
        rect.move(movement);
    }
    void drawTo(sf::RenderWindow &window) {
        window.draw(rect);
    }
private:
    sf::RectangleShape rect;
    bool up, down, left, right;
};




#endif //OOP_ENTITY_H
