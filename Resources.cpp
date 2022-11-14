////
//// Created by Matei on 11/12/2022.
////
//

#include "SFML/Audio.hpp"
#include "Resources.h"

template<typename Resource>
Resource createResource(const std::string& filename) {
    Resource newResource;

    newResource.loadFromFile(filename);

    return std::move(newResource);
}



sf::Font Resources::defaultFont = createResource<sf::Font>("resources/font2.ttf");
sf::Texture Resources::popupWindow = createResource<sf::Texture>("resources/popup.png");
sf::Texture Resources::animatedBackground = createResource<sf::Texture>("resources/AnimatedBackground2.png");

