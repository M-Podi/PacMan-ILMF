#ifndef OOP_POPUP_H
#define OOP_POPUP_H
#include "TextDisp.h"

class Popup:TextDisp {
private:
    sf::RectangleShape popup, shadow;
//    sf::Text text;
    sf::Vector2f Position;
//    std::string txt;
public:
    Popup();
    Popup(const std::string &popupText, sf::Vector2f popupSize, int charSize, sf::Color textColor,sf::Texture &texture,sf::Font &fonts);
    ~Popup();

    std::string getText() const;
    [[maybe_unused]] void setCharSize(int c);
    void setFont(sf::Font &fonts);

    void setPosition(sf::Vector2f point, sf::Vector2f square);
    void draw(sf::RenderWindow &window) override;
};

#endif //OOP_POPUP_H
