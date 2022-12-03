#include "Button.h"
#include <utility>

Button::Button() = default;

Button::Button(const std::string &btnText, int charSize, sf::Font &fonts) {
    setText(std::move(btnText));
    setCharSize(charSize);
    text.setFont(fonts);
    text.setOrigin(0.f,static_cast<float>(charSize)/2.f);
}
void Button::Innit(const std::string &btnText, int charSize, sf::Font &fonts){
    setText(std::move(btnText));
    setCharSize(charSize);
    text.setFont(fonts);
    text.setOrigin(0.f,static_cast<float>(charSize)/2.f);
}
bool Button::isMouseOver(sf::RenderWindow &window) const {
    sf::Vector2i mouseCoords({sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y});

    sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

    if (this->text.getGlobalBounds().contains(realCoords)) {
        return true;
    }
    return false;
}


