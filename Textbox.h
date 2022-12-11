#pragma once
#ifndef OOP_TEXTBOX_H
#define OOP_TEXTBOX_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
    Textbox();
    [[maybe_unused]] Textbox(int size,sf::Color color, bool sel);
    void Innit(int size,sf::Color color, bool sel);
    void setFont(sf::Font &font);
    void setPosition(sf::Vector2f pos);
    void setLimit(bool ToF);
    void setLimit(bool ToF, int lim);
    void setSelected(bool sel);
    std::string getText();
    void drawTo(sf::RenderWindow &window);
    void setCharacterSize(int size);
    void setColor(sf::Color color);
    void typedOn(sf::Event input);
private:
    sf::Text textbox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    unsigned long limit;
    void inputLogic(int charTyped);
    void deleteLastChar();
};


#endif //OOP_TEXTBOX_H
