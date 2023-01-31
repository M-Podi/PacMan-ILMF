#pragma once
#ifndef OOP_TEXTDISP_H
#define OOP_TEXTDISP_H
#include "SFML/Graphics.hpp"

class TextDisp{
protected:
    sf::Text text;
    sf::Vector2f position;
    std::string txt;
public:
    TextDisp();

    TextDisp(const std::string &Text, int charSize, sf::Color textColor,sf::Font &fonts, sf::Vector2f position);
    ~TextDisp();

    std::string getText() const;
    void setText(const std::string &other);
    [[maybe_unused]] void setCharSize(int c);

    void setPosition(sf::Vector2f position);
    [[maybe_unused]] void setTextColor(sf::Color textColor);

    virtual void draw(sf::RenderWindow &window);

};


#endif //OOP_TEXTDISP_H
