#pragma once
#ifndef _HEADER_Button
#define _HEADER_Button
#include <SFML/Graphics.hpp>
#include<iostream>

class Button {
private:
    sf::RectangleShape button;
    sf::Text text;//, shadow;
    std::string btnText;
    sf::Vector2f buttonSize;
    int charSize=1;
    sf::Color bgColor;
    sf::Color textColor;
    std::string txt;
public:
    Button();
    Button(const std::string &btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor);
    void setText(std::string t);
    void setCharSize(int c);
    void setFont(sf::Font& font);
    void setBackColor(sf::Color color);
    void setTextColor(sf::Color color);
    void drawTo(sf::RenderWindow& window);
    void setSize(sf::Vector2f s);
    void setPositions(sf::Vector2f Pos1,sf::Vector2f Pos2);
    std::string getText() const;
    bool isMouseOver(sf::RenderWindow& window) const;
    friend std::ostream& operator<<(std::ostream& os, const Button& button);
};

#endif