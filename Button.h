#pragma once
#ifndef _HEADER_Button
#define _HEADER_Button

#include <SFML/Graphics.hpp>
#include<iostream>
#include "TextDisp.h"

class Button{
private:
    sf::Text text;
public:
    Button();
    Button(const std::string &popupText, int charSize,sf::Font &fonts);
    bool isMouseOver(sf::RenderWindow &window) const;
    std::string getText() const;
    [[maybe_unused]] void setCharSize(int c);

    void setTextColor(sf::Color textColor);
    void setPosition(sf::Vector2u point);
    void draw(sf::RenderWindow &window);
};

#endif