#include "Popup.h"
Popup::Popup()=default;
Popup::~Popup()=default;
Popup::Popup(const std::string &popupText, sf::Vector2f popupSize, int charSize, sf::Color textColor,sf::Texture &texture,sf::Font &fonts) {
    txt=popupText;
    popup.setSize(popupSize);
    popup.setTexture(&texture);
    text.setString(txt);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(5);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);
    text.setFont(fonts);
}

std::string Popup::getText() const {
    return txt;
}
[[maybe_unused]] void Popup::setCharSize(int c) {
    text.setCharacterSize(c);
}
void Popup::setFont(sf::Font &fonts) {
    text.setFont(fonts);
}
void Popup::setPosition(sf::Vector2f point, sf::Vector2f square) {
    popup.setPosition(point);
    Position = point;

    float xPos = square.x;
    float yPos = square.y;
    text.setPosition(xPos, yPos);
}
void Popup::draw(sf::RenderWindow &window) {
    window.draw(popup);
    window.draw(text);
}