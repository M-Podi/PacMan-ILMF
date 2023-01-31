#include "TextDisp.h"

TextDisp::TextDisp()=default;

TextDisp::~TextDisp()=default;

TextDisp::TextDisp(const std::string &Text, int charSize, sf::Color textColor,sf::Font &fonts, sf::Vector2f position){
    text.setString(Text);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(5);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);
    text.setOrigin(text.getGlobalBounds().getSize().x,text.getLocalBounds().getSize().y);
    text.setFont(fonts);
    text.setPosition(position);
}

std::string TextDisp::getText() const{
    return text.getString();
}

void TextDisp::setText(const std::string &other){
    text.setString(other);
}

[[maybe_unused]] void TextDisp::setCharSize(int c) {
    text.setCharacterSize(c);
}

void TextDisp::setPosition(sf::Vector2f square) {
    text.setPosition(square);
}

[[maybe_unused]] void TextDisp::setTextColor(sf::Color textColor){
    text.setFillColor(textColor);
}

void TextDisp::draw(sf::RenderWindow &window) {
    window.draw(text);
}
