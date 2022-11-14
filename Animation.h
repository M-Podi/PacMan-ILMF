//
// Created by Matei on 11/7/2022.
//

#ifndef OOP_ANIMATION_H
#define OOP_ANIMATION_H

#include"SFML/Graphics.hpp"

class Animation {
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount,float switchTime);
    ~Animation();
    void Update(int row,float deltaTime);
    sf::IntRect getuvRect();
private:
    sf::IntRect uvRect;
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    float totalTime;
    float switchTime;
};


#endif //OOP_ANIMATION_H
