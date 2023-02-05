#pragma once
#ifndef OOP_TEXTDISP_H
#define OOP_TEXTDISP_H
#include "SFML/Graphics.hpp"
template <typename T>
class TextDisp{
protected:
    sf::Text text;
    T x,y;
    std::string txt;
public:
    TextDisp()=default;

    TextDisp(const std::string &Text, int charSize, sf::Color textColor,sf::Font &fonts, T x, T y):x(x),y(y){
        text.setString(Text);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
        text.setOrigin(text.getGlobalBounds().getSize().x,text.getLocalBounds().getSize().y);
        text.setFont(fonts);
        text.setPosition(x,y);
    };
    ~TextDisp()=default;

    std::string getText() const{
        return text.getString();
    };
    void setText(const std::string &other){
        text.setString(other);
    };
    [[maybe_unused]] void setCharSize(int c) {
        text.setCharacterSize(c);
    };

    void setPosition(T a, T b) {
        text.setPosition(a,b);
    };
    [[maybe_unused]] void setTextColor(sf::Color textColor){
        text.setFillColor(textColor);
    };

    virtual void draw(sf::RenderWindow &window) {
        window.draw(text);
    };

};


#endif //OOP_TEXTDISP_H
