#include "TextDisp.h"

TextDisp::TextDisp()=default;
TextDisp::~TextDisp()=default;
TextDisp::TextDisp(const std::string &popupText, int charSize, sf::Color textColor): txt(popupText){
    text.setString(txt);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(5);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);
    text.setOrigin(text.getGlobalBounds().getSize().x,text.getLocalBounds().getSize().y);
}
void TextDisp::Innit(const std::string &popupText, int charSize, sf::Color textColor){
    txt=popupText;
    text.setString(txt);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(5);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);
    text.setOrigin(text.getGlobalBounds().getSize().x,text.getLocalBounds().getSize().y);
}
std::string TextDisp::getText() const{
    return txt;
}
void TextDisp::setText(const std::string &other){
    txt=other;
    text.setString(txt);
}
[[maybe_unused]] void TextDisp::setCharSize(int c) {
    text.setCharacterSize(c);
    //shadow.setCharacterSize(c + 2);
}
void TextDisp::setFont(sf::Font &fonts) {
    text.setFont(fonts);
    //shadow.setFont(fonts);
}
void TextDisp::setPosition(sf::Vector2f square) {
    float xPos = square.x;
    float yPos = square.y;
    text.setPosition(xPos, yPos);
}
[[maybe_unused]] void TextDisp::setTextColor(sf::Color textColor){
    text.setFillColor(textColor);
}
void TextDisp::draw(sf::RenderWindow &window) {
    window.draw(text);
}
