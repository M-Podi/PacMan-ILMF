////
//// Created by Matei on 11/12/2022.
////
//

#include "SFML/Audio.hpp"
#include "Resources.h"

template<typename Resource>
Resource createResource(const std::string &filename) {
    Resource newResource;

    newResource.loadFromFile(filename);

    return newResource;
}


sf::Font Resources::defaultFont = createResource<sf::Font>("resources/DefaultFont.ttf");
sf::Texture Resources::popupWindow = createResource<sf::Texture>("resources/popup.png");
sf::Texture Resources::animatedBackground = createResource<sf::Texture>("resources/AnimatedBackground2.png");
sf::Texture Resources::Pac = createResource<sf::Texture>("resources/PAC3.png");
sf::Texture Resources::wall = createResource<sf::Texture>("resources/wallTexture.png");
sf::Texture Resources::bridge = createResource<sf::Texture>("resources/bridge.png");
sf::Texture Resources::RedG = createResource<sf::Texture>("resources/GhostRed.png");
sf::Texture Resources::BlueG = createResource<sf::Texture>("resources/GhostBlue.png");
sf::Texture Resources::PinkG = createResource<sf::Texture>("resources/GhostPink.png");
sf::Texture Resources::OrangeG = createResource<sf::Texture>("resources/GhostOrange.png");


