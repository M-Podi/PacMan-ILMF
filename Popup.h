//
// Created by Matei on 11/30/2022.
//

#ifndef OOP_POPUP_H
#define OOP_POPUP_H
#include "TextDisp.h"

class Popup:TextDisp {
private:
    sf::RectangleShape popup, shadow;
    sf::Text text;
    sf::Vector2f Position;
    std::string txt;
public:
    Popup()=default;
    Popup(const std::string &popupText, sf::Vector2f popupSize, int charSize, sf::Color textColor,sf::Texture &texture): txt(popupText) {
        popup.setSize(popupSize);
        text.setString(txt);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
        popup.setTexture(&texture);
    }
    void Innit(const std::string &popupText, sf::Vector2f popupSize, int charSize, sf::Color textColor,sf::Texture &texture,sf::Font &fonts) {
        txt=popupText;
        popup.setSize(popupSize);
        text.setString(txt);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
        text.setFont(fonts);
        popup.setTexture(&texture);
    }
    ~Popup() = default;

    std::string getText() const {
        return txt;
    }
    [[maybe_unused]] void setCharSize(int c) {
        text.setCharacterSize(c);
    }
    void setFont(sf::Font &fonts) {
        text.setFont(fonts);
    }

    void setPosition(sf::Vector2f point, sf::Vector2f square) {
        popup.setPosition(point);
        shadow.setPosition(point);
        Position = point;

        float xPos = square.x;
        float yPos = square.y;
        text.setPosition(xPos, yPos);
    }

    void draw(sf::RenderWindow &window) {
        window.draw(shadow);
        window.draw(popup);
        window.draw(text);
    }
};

#endif //OOP_POPUP_H
