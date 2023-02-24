#include "Entity.h"

Entity::Entity() =default;
Entity::Entity(float x, float y,sf::Texture &texture,int frames) {
    rect.setSize(sf::Vector2f(x, y));
    rect.setRotation(0.f);
    animation2.Innit(&texture,sf::Vector2u(frames,1),0.1f);
    rect.setSize(sf::Vector2f(x, y));
    rect.setTexture(&texture);
    rect.setOrigin(rect.getLocalBounds().width / 2,rect.getLocalBounds().height/2);
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


bool Entity::canMove(const sf::Vector2<float>& move,const std::vector<std::string> &map_sketch) {
    return map_sketch[move.y][move.x]=='#';
}
void Entity::update2(float deltaTime){
    animation2.Update(0,deltaTime);
    this->rect.setTextureRect(animation2.getuvRect());
}

void Entity::move(const std::vector<std::string> &map_sketch,int screenSize) {

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
    if(rect.getPosition().x+1<sidebar)
        rect.setPosition(rect.getPosition()+sf::Vector2f(map_sketch.size()*rect.getSize().x,0));
    else if(rect.getPosition().x>sidebar+map_sketch.size()*rect.getSize().x)
        rect.setPosition(rect.getPosition()-sf::Vector2f(map_sketch.size()*rect.getSize().x,0));
}


void Entity::drawTo(sf::RenderWindow &window) {
    window.draw(rect);
}

