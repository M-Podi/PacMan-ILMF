#pragma once
#ifndef _HEADER_Button
#define _HEADER_Button

#include <SFML/Graphics.hpp>
#include<iostream>
#include "TextDisp.h"

class Button: public TextDisp {
public:
    Button();
    Button(const std::string &btnText, int charSize, sf::Font &fonts);
    void Innit(const std::string &btnText, int charSize, sf::Font &fonts);
    bool isMouseOver(sf::RenderWindow &window) const;
};

#endif