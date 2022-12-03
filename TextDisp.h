//
// Created by Matei on 11/30/2022.
//
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
    TextDisp()=default;
    TextDisp(const std::string &popupText, int charSize, sf::Color textColor): txt(popupText) {
        text.setString(txt);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
        text.setOrigin(text.getGlobalBounds().getSize().x,text.getLocalBounds().getSize().y);
    }
    void Innit(const std::string &popupText, int charSize, sf::Color textColor){
        txt=popupText;
        text.setString(txt);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
        text.setOrigin(text.getGlobalBounds().getSize().x,text.getLocalBounds().getSize().y);
    }
    ~TextDisp() = default;

    std::string getText() const {
        return txt;
    }
    void setText(const std::string &other){
        txt=other;
        text.setString(txt);
    }
    [[maybe_unused]] void setCharSize(int c) {
        text.setCharacterSize(c);
        //shadow.setCharacterSize(c + 2);
    }

    void setFont(sf::Font &fonts) {
        text.setFont(fonts);
        //shadow.setFont(fonts);
    }

    void setPosition(sf::Vector2f square) {
        float xPos = square.x;
        float yPos = square.y;
        text.setPosition(xPos, yPos);
    }
    [[maybe_unused]] void setTextColor(sf::Color textColor){
        text.setFillColor(textColor);
    }

    void draw(sf::RenderWindow &window) {
        window.draw(text);
    }
};


#endif //OOP_TEXTDISP_H
