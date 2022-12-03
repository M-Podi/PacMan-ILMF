#include "Animation.h"

[[maybe_unused]]Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::Animation()=default;

Animation::~Animation()=default;

void Animation::Innit(sf::Texture* texture, sf::Vector2u otherimageCount,float otherswitchTime){
    this->imageCount = otherimageCount;
    this->switchTime = otherswitchTime;
    totalTime = 0.0f;
    currentImage.x = 0;
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

sf::IntRect Animation::getuvRect() {
    return uvRect;
}

void Animation::Update(int row, float deltaTime) {
    currentImage.y = row;
    totalTime += deltaTime;
    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x > imageCount.x - 1)
            currentImage.x = 0;
    }
    uvRect.left = int(currentImage.x) * uvRect.width;
    uvRect.top = int(currentImage.y) * uvRect.height;
}