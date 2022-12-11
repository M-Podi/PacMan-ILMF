#include "Entity.h"

Entity::Entity() =default;
Entity::Entity(float x, float y) {
    rect.setSize(sf::Vector2f(x, y));
    up = false;
    down = false;
    left = false;
    right = false;
}
void Entity::Innit(float x, float y) {
    rect.setSize(sf::Vector2f(x, y));
    rect.setOrigin(rect.getGlobalBounds().getSize().x/2.f,rect.getGlobalBounds().getSize().y/2.f);
    rect.setRotation(0.f);
    animation2.Innit(&Resources::Pac,sf::Vector2u(4,1),0.1f);
    rect.setSize(sf::Vector2f(x, y));
    rect.setTexture(&Resources::Pac);
    up = false;
    down = false;
    left = false;
    right = false;

}
void Entity::setPosition(sf::Vector2f Pos){
    rect.setPosition(Pos.x+rect.getSize().x/2,Pos.y+rect.getSize().y/2);
}
void Entity::processEvents(sf::Keyboard::Key key, bool checkPressed) {
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
void Entity::update(float deltaTime,std::vector<sf::RectangleShape> wall) {
    sf::Vector2f movement;
    animation2.Update(0,deltaTime);
    this->rect.setTextureRect(animation2.getuvRect());
    bool w=false;
    if (up)
        movement.y -= 0.3f;
    if (down)
        movement.y += 0.3f;
    if (left)
        movement.x -= 0.3f;
    if (right)
        movement.x += 0.3f;
    for (int i = 0; i < wall.size(); i++) {
        if (rect.getGlobalBounds().intersects(wall[i].getGlobalBounds()))
            w = true;
    }
    if (!w) {
        lastPos = rect.getPosition();
        rect.move(movement);
    }
    if (w)
        rect.setPosition(lastPos);
}

void Entity::drawTo(sf::RenderWindow &window) {
    window.draw(rect);
}