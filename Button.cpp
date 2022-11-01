#include "Button.h"

#include <utility>

Button::Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor) {
    button.setSize(buttonSize);
    button.setFillColor(bgColor);
    //text.setString(btnText);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);
    //shadow.setString(btnText);
    setText(std::move(btnText));
    shadow.setCharacterSize(charSize + 2);
    shadow.setFillColor(sf::Color::Black);
}

void Button::setText(std::string t) {
    txt=t;
    text.setString(t);
    shadow.setString(t);
}

std::string Button::getText() const {
    return txt;
}

void Button::setSize(sf::Vector2f s) {
    button.setSize(s);
}

[[maybe_unused]] void Button::setCharSize(int c) {
    text.setCharacterSize(c);
    shadow.setCharacterSize(c + 4);
}

void Button::setFont(sf::Font &fonts) {
    text.setFont(fonts);
    shadow.setFont(fonts);
}

[[maybe_unused]] void Button::setBackColor(sf::Color color) {
    button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
    text.setFillColor(color);
    shadow.setFillColor(sf::Color::Black);
}


void Button::setPositions(sf::Vector2f point, sf::Vector2f btn) {
    button.setPosition(point);
    float div = 2.0 + btn.y / btn.x;

    //float xPos = point.x + button.getLocalBounds().width / 2 - text.getLocalBounds().width / 2;
    //float yPos = point.y + button.getLocalBounds().height / 2 - text.getLocalBounds().height / 2;

    float xPos = (point.x + btn.x / div) - (text.getLocalBounds().width / 2);
    float yPos = (point.y + btn.y / div) - (text.getLocalBounds().height / 2);

    text.setPosition(xPos, yPos);
    shadow.setPosition(xPos, yPos);
}

void Button::drawTo(sf::RenderWindow &window) {
    window.draw(button);
    window.draw(shadow);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &window) const {
    sf::Vector2i mouseCoords({sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y});

    sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);

    float mouseX = realCoords.x;
    float mouseY = realCoords.y;

    int btnPosX = button.getPosition().x;
    int btnPosY = button.getPosition().y;

    int btnxPosWidth = button.getPosition().x + button.getGlobalBounds().width;
    int btnyPosHeight = button.getPosition().y + button.getGlobalBounds().height;

    if (mouseX < btnxPosWidth + 20 && mouseX > btnPosX - 20 && mouseY < btnyPosHeight + 20 && mouseY > btnPosY - 20) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Button &btn1) {
    os << "A fost afisat butonul cu textul " << btn1.getText() << "\n";
    return os;
}


