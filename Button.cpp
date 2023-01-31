#include "Button.h"
#include <utility>

Button::Button() = default;


bool Button::isMouseOver(sf::RenderWindow &window) const {
    sf::Vector2i mouseCoords({sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y});

    sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

    if (this->text.getGlobalBounds().contains(realCoords)) {
        return true;
    }
    return false;
}

Button::Button(const std::string &Text, int charSize,sf::Font &fonts){
    text.setString(Text);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(5);
    text.setCharacterSize(charSize);
    text.setOrigin(text.getGlobalBounds().getSize().x,text.getLocalBounds().getSize().y);
    text.setFont(fonts);

}

std::string Button::getText() const{
    return text.getString();
}


[[maybe_unused]] void Button::setCharSize(int c) {
    text.setCharacterSize(c);
}

void Button::setPosition(sf::Vector2u square) {
    sf::Vector2f pos;
    pos.x=static_cast<int>(square.x);
    pos.y=static_cast<int>(square.y);
    text.setPosition(pos);
}

[[maybe_unused]] void Button::setTextColor(sf::Color textColor){
    text.setFillColor(textColor);
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(text);
}


