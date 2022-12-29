#include "Entity.h"

Entity::Entity() =default;
Entity::Entity(float x, float y,sf::Texture &texture,int frames) {
    rect.setSize(sf::Vector2f(x, y));
    rect.setSize(sf::Vector2f(x, y));
    rect.setRotation(0.f);
    animation2.Innit(&texture,sf::Vector2u(frames,1),0.1f);
    rect.setSize(sf::Vector2f(x, y));
    rect.setTexture(&texture);
    rect.setOrigin(rect.getGlobalBounds().getSize()/2.f);
}
sf::Vector2f Entity::GetPosition() {
    return rect.getPosition();
}
sf::Rect<float> Entity::GetGlobalBounds(){
    return rect.getGlobalBounds();
}
void Entity::setPosition(sf::Vector2f Pos){
    rect.setPosition(Pos+rect.getSize()/2.f);
}


bool Entity::canMove(const sf::Vector2<float>& move,const std::vector<sf::RectangleShape> &wall) {
    for (const auto& w:wall) {
        if(w.getGlobalBounds().contains(move))
            return false;
    }
    return true;
}
void Entity::update2(float deltaTime){
    animation2.Update(0,deltaTime);
    this->rect.setTextureRect(animation2.getuvRect());
}
void Entity::move(std::vector<sf::CircleShape>& point,std::vector<sf::CircleShape>& powerup,const std::vector<std::string> &map_sketch,int screenSize) {
    for (int i = 0; i < static_cast<int>(point.size()); i++) {
        if(point[i].getGlobalBounds().contains(rect.getPosition())) {
            point.erase(point.begin() + i);
        }
    }
    for (int i = 0; i < static_cast<int>(powerup.size()); i++) {
        if(powerup[i].getGlobalBounds().contains(rect.getPosition())) {
            powerup.erase(powerup.begin() + i);
        }
    }

    if (currentDirection == NONE)
    {
        return;
    }
    sf::Vector2f coords=rect.getPosition();
    coords += directions[currentDirection] * speed;
    remaining -= speed;

    if (remaining <= 0) {
        coords += directions[currentDirection] * remaining;
        previousDirection = currentDirection;
        currentDirection = NONE;
    }
    rect.setPosition(coords);
    int sidebar = (screenSize - rect.getSize().x * map_sketch.size()) / 2;
    if(rect.getPosition().x<sidebar)
        rect.setPosition(rect.getPosition()+sf::Vector2f(map_sketch.size()*rect.getSize().x,0));
    else if(rect.getPosition().x>sidebar+map_sketch.size()*rect.getSize().x)
        rect.setPosition(rect.getPosition()-sf::Vector2f(map_sketch.size()*rect.getSize().x,0));
}


void Entity::drawTo(sf::RenderWindow &window) {
    window.draw(rect);
}

