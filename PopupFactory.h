#ifndef OOP_POPUPFACTORY_H
#define OOP_POPUPFACTORY_H
#include "Popup.h"
#include "Resources.h"

class PopupFactory {
public:
    static Popup simplePopup(const std::string &text,const sf::RenderWindow &window){
        return {text, sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 50,
                     sf::Color(130,0,2,255),Resources::popupWindow,Resources::defaultFont};
    }
};


#endif //OOP_POPUPFACTORY_H
