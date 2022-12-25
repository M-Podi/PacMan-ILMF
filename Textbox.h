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
    Textbox(int size,sf::Color color, bool sel,sf::Font &fonts);
    void setPosition(sf::Vector2f pos);
    void setLimit(bool ToF);
    void setLimit(bool ToF, int lim);
    //void setSelected(bool sel);
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
    unsigned long limit=0;
    void inputLogic(int charTyped);
    void deleteLastChar();
};


#endif //OOP_TEXTBOX_H
