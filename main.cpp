#include "Player.h"
#include <iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
//#include "Game.h"
#include "Button.h"


class Popup {
private:
    sf::RectangleShape popup, shadow;
    sf::Text text;
    sf::Vector2f Position;
    std::string txt;
    int charSize;

public:
    Popup(std::string popupText, sf::Vector2f popupSize, int charSize, sf::Color bgColor, sf::Color textColor) {
        txt = popupText;
        popup.setSize(popupSize);
        popup.setFillColor(bgColor);
        shadow.setSize(popupSize + sf::Vector2f(1, 1));
        shadow.setFillColor(sf::Color::White);
        text.setString(popupText);;
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
    }

    ~Popup() {
        //std::cout << "Am mai apelat un deconstructor\n";
    }

    std::string getText() const {
        return txt;
    }

    void setPosition(sf::Vector2f point, sf::Vector2f square) {
        popup.setPosition(point);
        shadow.setPosition(point);
        Position = point;
        //float div = 2.0 + btn.y / btn.x;

        //float xPos = point.x + button.getLocalBounds().width / 2 - text.getLocalBounds().width / 2;
        //float yPos = point.y + button.getLocalBounds().height / 2 - text.getLocalBounds().height / 2;

        //float xPos = (point.x + btn.x / div) - (popup.getLocalBounds().width / 2);
        //float yPos = (point.y + btn.y / div) - (text.getLocalBounds().height / 2);

        float xPos = square.x / 2;
        float yPos = square.y / 3;
        text.setPosition(xPos, yPos);
    }

    //void setFont(sf::Font font) {
    //text.setFont(font);
    //}
    void draw(sf::RenderWindow &window) {
        window.draw(shadow);
        window.draw(popup);
        window.draw(text);
    }

    friend std::ostream &operator<<(std::ostream &os, const Popup &popup);
};

std::ostream &operator<<(std::ostream &os, const Popup &popup) {
    os << "A fost afisat popup-ul cu titlul " << popup.getText() << "\n";
    return os;
}


int main() {

    Player player2("Matei");
    std::cout << player2;

    sf::VideoMode mode(1920, 1080);
    sf::RenderWindow window(mode, "Pac-Man Podi");

    //Game game;

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("interaction2.wav")) {
        std::cout << "Eroare" << std::endl;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);

    //Font
    sf::Font font1;
    font1.loadFromFile("MenuFont.ttf");


    //Background
    sf::Texture pTexture;
    sf::Sprite background;


    if (!pTexture.loadFromFile("MenuBackground.jpg"))
        std::cout << "Error could not load background imageeeeeeeee" << std::endl;
    background.setTexture(pTexture);

    Button btn1("Play", {strlen("Play") * 17.f, 30.f}, 55, sf::Color::Transparent,
                sf::Color::Yellow);//, sf::Sound sound1);
    btn1.setFont(font1);
    btn1.setPositions(sf::Vector2f(window.getSize().x / 7 * 5, window.getSize().x / 8),
                      sf::Vector2f(strlen("Play") * 17, 15));
    std::cout << btn1;

    Button btn2("Settings", {strlen("Settings") * 17.f, 30.f}, 55, sf::Color::Transparent,
                sf::Color::Yellow);//,sf::Sound sound1);
    btn2.setFont(font1);
    btn2.setPositions(sf::Vector2f(window.getSize().x / 7 * 5, window.getSize().x / 8 * 2),
                      sf::Vector2f(strlen("Settings") * 17, 15));


    Button btn3("Quit", {strlen("Quit") * 17.f, 30.f}, 55, sf::Color::Transparent,
                sf::Color::Yellow);//,sf::Sound sound1);
    btn3.setFont(font1);
    btn3.setPositions(sf::Vector2f(window.getSize().x / 7 * 5, window.getSize().x / 8 * 3),
                      sf::Vector2f(strlen("Quit") * 17, 15));


    Button opt1("Yes", {strlen("Play") * 17.f, 30.f}, 55, sf::Color::Transparent, sf::Color::Yellow);
    opt1.setFont(font1);
    opt1.setPositions(sf::Vector2f(window.getSize().x / 25 * 11, window.getSize().y / 7 * 4),
                      sf::Vector2f(strlen("Play") * 17, 15));
    Button opt2("No", {strlen("Play") * 17.f, 30.f}, 55, sf::Color::Transparent, sf::Color::Yellow);
    opt2.setFont(font1);
    opt2.setPositions(sf::Vector2f(window.getSize().x / 20 * 11, window.getSize().y / 7 * 4),
                      sf::Vector2f(strlen("Play") * 17, 15));

    Button done("Done", {strlen("Done") * 17.f, 30.f}, 55, sf::Color::Transparent, sf::Color::Yellow);
    done.setFont(font1);
    done.setPositions(sf::Vector2f(window.getSize().x / 20 * 11, window.getSize().y / 7 * 4),
                      sf::Vector2f(strlen("Play") * 17, 15));

    Button go("Go", {strlen("Done") * 17.f, 30.f}, 55, sf::Color::Transparent, sf::Color::Yellow);
    go.setFont(font1);
    go.setPositions(sf::Vector2f(window.getSize().x / 20 * 11, window.getSize().y / 7 * 4),
                    sf::Vector2f(strlen("Play") * 17, 15));

    Popup quit("Are you sure you want to quit?", sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3), 55,
               sf::Color::Black, sf::Color::Yellow);
    //quit.setFont(font1);
    quit.setPosition(sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                  (window.getSize().y - window.getSize().y / 3) / 2),
                     sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    std::cout<<quit<<"\n";
    Popup settings("Audio Level", sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3), 55, sf::Color::Black,
                   sf::Color::Yellow);
    //settings.setFont(font1);
    settings.setPosition(sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                      (window.getSize().y - window.getSize().y / 3) / 2),
                         sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    Popup play("Enter your username:", sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3), 55,
               sf::Color::Black, sf::Color::Yellow);
    //settings.setFont(font1);
    play.setPosition(sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                  (window.getSize().y - window.getSize().y / 3) / 2),
                     sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    int resp = 0;
    while (window.isOpen()) {

        if (resp == 0) {
            std::cout << "Afisez mainmenu1\n";
            std::cout << "Afisez mainmenu2\n";
            window.clear();
            window.draw(background);
            btn1.drawTo(window);
            btn2.drawTo(window);
            btn3.drawTo(window);
            window.display();
        }
        if (resp == 1) {
            window.clear();
            window.draw(background);
            quit.draw(window);
            opt1.drawTo(window);
            opt2.drawTo(window);
            window.display();
        }
        if (resp == 2) {
            window.clear();
            window.draw(background);
            settings.draw(window);
            done.drawTo(window);
            window.display();
        }
        if (resp == 3) {
            window.clear();
            window.draw(background);
            play.draw(window);
            go.drawTo(window);
            window.display();
        }
        sf::Event event;
        //cursor.setPosition(Mouse.getPosition(window).x, Mouse.getPosition(window).y);

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                case sf::Event::MouseMoved:
                    if (btn1.isMouseOver(window)) {
                        btn1.setTextColor(sf::Color::Red);
                    } else
                        btn1.setTextColor(sf::Color::Yellow);
                    if (btn2.isMouseOver(window)) {
                        btn2.setTextColor(sf::Color::Red);
                    } else
                        btn2.setTextColor(sf::Color::Yellow);
                    if (btn3.isMouseOver(window)) {
                        btn3.setTextColor(sf::Color::Red);
                    } else
                        btn3.setTextColor(sf::Color::Yellow);
                    if (opt1.isMouseOver(window)) {
                        opt1.setTextColor(sf::Color::Red);
                    } else {
                        opt1.setTextColor(sf::Color::Yellow);
                    }
                    if (opt2.isMouseOver(window)) {
                        opt2.setTextColor(sf::Color::Red);
                    } else {
                        opt2.setTextColor(sf::Color::Yellow);
                    }
                    if (done.isMouseOver(window)) {
                        done.setTextColor(sf::Color::Red);
                    } else {
                        done.setTextColor(sf::Color::Yellow);
                    }
                    if (go.isMouseOver(window)) {
                        go.setTextColor(sf::Color::Red);
                    } else {
                        go.setTextColor(sf::Color::Yellow);
                    }

                    break;
                case sf::Event::MouseButtonPressed:
                    if (go.isMouseOver(window) && resp == 3) {
                        window.clear();
                        window.draw(background);
                        window.display();
                        resp = 4;
                    }
                    if (opt1.isMouseOver(window) && resp == 1) {
                        window.close();
                        return 0;
                    }
                    if (opt2.isMouseOver(window) && resp == 1) {
                        std::cout << "Ai ales optiunea 2";
                        resp = 0;
                        continue;
                    }
                    if (done.isMouseOver(window) && resp == 2) {
                        //std::cout << "Ai ales optiunea 2";
                        resp = 0;
                        continue;
                    }
                    if (btn3.isMouseOver(window) && resp == 0) {
                        resp = 1;
                    }
                    if (btn2.isMouseOver(window) && resp == 0) {
                        resp = 2;
                    }
                    if (btn1.isMouseOver(window) && resp == 0) {
                        resp = 3;
                    }
            }

        }

    }
    return 0;
}
/*
//Game loop;
while (game.getWindowIsOpen())
{
    game.render();
    game.update();

    //cursor.setPosition(Mouse.getPosition(window).x, Mouse.getPosition(window).y);


    //draw on the screen
    //window.clear();
    //window.draw(background);
    //
    //btn2.drawTo(window);
    //btn3.drawTo(window);
    //window.draw(cursor);
    //window.display();
}
return 0;
}*/