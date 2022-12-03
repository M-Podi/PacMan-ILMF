//
// Created by Matei on 11/9/2022.
//

#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Animation.h"
#include "Resources.h"
class Entity {
public:
    Entity()=default;
    Entity(float x, float y) {
        rect.setSize(sf::Vector2f(x, y));
        up = false;
        down = false;
        left = false;
        right = false;
    }
    void Innit(float x, float y) {
        rect.setSize(sf::Vector2f(x, y));
        rect.setOrigin(rect.getGlobalBounds().getSize().x/2.f,rect.getGlobalBounds().getSize().y/2.f);
        rect.setRotation(0.f);
        animation2.Innit(&Resources::Pac,sf::Vector2u(4,1),0.1f);
        rect.setSize(sf::Vector2f(x, y));
        rect.setTexture(&Resources::Pac);
        rect.setPosition(rect.getGlobalBounds().getSize().x/2,rect.getGlobalBounds().getSize().y/2);
        up = false;
        down = false;
        left = false;
        right = false;

    }

    void processEvents(sf::Keyboard::Key key, bool checkPressed) {
        if (checkPressed == true) {
            if (key == sf::Keyboard::Up || key == sf::Keyboard::W){
                up = true;
                rect.setRotation(0.f);
                rect.rotate(270.f);
            }
            if (key == sf::Keyboard::Down || key == sf::Keyboard::S){
                down = true;
                rect.setRotation(0.f);
                rect.rotate(90.f);

            }
            if (key == sf::Keyboard::Left || key == sf::Keyboard::A){
                left = true;
                rect.setRotation(0.f);
                rect.rotate(180.f);
            }
            if (key == sf::Keyboard::Right || key == sf::Keyboard::D){
                right = true;
                rect.setRotation(0.f);
            }
        } else {
            up = false;
            down = false;
            left = false;
            right = false;
        }
    }

    void update(sf::RenderWindow &window) {
        sf::Vector2f movement;
        if (up && rect.getPosition().y-rect.getGlobalBounds().getSize().y/2.f>0)
            movement.y -= 0.3f;
        if (down && rect.getPosition().y+rect.getGlobalBounds().getSize().y/2.f<(window.getSize().y-rect.getSize().y))
            movement.y += 0.3f;
        if (left && rect.getPosition().x-rect.getGlobalBounds().getSize().x/2.f>0)
            movement.x -= 0.3f;
        if (right&& rect.getPosition().x+rect.getGlobalBounds().getSize().x/2.f<window.getSize().x-rect.getSize().x)
            movement.x += 0.3f;
        rect.move(movement);
    }
    void update2(float deltaTime){
        animation2.Update(0,deltaTime);
        this->rect.setTextureRect(animation2.getuvRect());
    }
    void drawTo(sf::RenderWindow &window) {
        window.draw(rect);
    }

private:
    Animation animation2;
    sf::RectangleShape rect;
    bool up, down, left, right;
};


#endif //OOP_ENTITY_H
