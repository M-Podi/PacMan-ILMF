#include "Player.h"
#include <iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
//#include "Game.h"
#include "Button.h"
#include<cstring>
#include "Textbox.h"
#include "Animation.h"

class Popup {
private:
    sf::RectangleShape popup, shadow;
    sf::Text text;
    sf::Vector2f Position;
    std::string txt;
    //int charSize;

public:
    Popup(const std::string &popupText, sf::Vector2f popupSize, int charSize, sf::Color bgColor, sf::Color textColor): txt(popupText) {
        popup.setSize(popupSize);
        popup.setFillColor(bgColor);
        shadow.setSize(popupSize + sf::Vector2f(1, 1));
        shadow.setFillColor(sf::Color::White);
        text.setString(txt);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
    }

    ~Popup() {
        //std::cout << "Am mai apelat un deconstructor\n";
    }

    std::string getText() const {
        return txt;
    }
    [[maybe_unused]] void setCharSize(int c) {
        text.setCharacterSize(c);
        //shadow.setCharacterSize(c + 2);
    }

    void setFont(sf::Font &fonts) {
        text.setFont(fonts);
        //shadow.setFont(fonts);
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

        float xPos = square.x;
        float yPos = square.y;
        text.setPosition(xPos, yPos);
    }

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
    player2.setBestScore(0);
    player2.setName("Podi");
    player2.setTime(0);
    std::cout << player2;


    sf::VideoMode mode(1920, 1080);
    sf::RenderWindow window(mode, "Pac-Man Podi",sf::Style::Fullscreen);

    //Amimated Background
    sf::RectangleShape animatedBackground(sf::Vector2f(1920,1080));
    animatedBackground.setPosition(0,0);
    sf::Texture anBack;
    anBack.loadFromFile("resources/AnimatedBackground2.png");
    animatedBackground.setTexture(&anBack);
    Animation animation(&anBack,sf::Vector2u(8,1),0.15f);
    float deltaTime=0.0f;
    sf::Clock clock;

    //Sound
    sf::Music music, music2, music3;
    music.openFromFile("resources/GameMusic.flac");
    music2.openFromFile("resources/Music2.flac");
    music3.openFromFile("resources/Music3.flac");

    //music.setVolume(10);
    music.setVolume(30);
    music2.setVolume(30);
    music3.setVolume(30);

    //Font
    sf::Font font1;
    font1.loadFromFile("resources/font2.ttf");


    Button btn1("   Play", {strlen("Play") * 30.f, 30.f}, 77, sf::Color::Transparent,
                sf::Color(130,0,2,255));//, sf::Sound sound1);
    btn1.setFont(font1);
    btn1.setPositions(sf::Vector2f(window.getSize().x / 8 * 6, window.getSize().y * 55 / 100),
                      sf::Vector2f(strlen("Play") * 17, 15));
    std::cout << btn1;

    Button btn2("     Settings", {strlen("Settings") * 30.f, 30.f}, 77, sf::Color::Transparent,
                sf::Color(130,0,2,255));//,sf::Sound sound1);
    btn2.setFont(font1);
    btn2.setPositions(sf::Vector2f(window.getSize().x / 8 * 6, window.getSize().y * 70 / 100),
                      sf::Vector2f(strlen("Settings") * 17, 15));


    Button btn3("   Quit", {strlen("Quit") * 30.f, 30.f}, 77, sf::Color::Transparent,
                sf::Color(130,0,2,255));//,sf::Sound sound1);
    btn3.setFont(font1);
    btn3.setPositions(sf::Vector2f(window.getSize().x / 8 * 6, window.getSize().y * 85 / 100),
                      sf::Vector2f(strlen("Quit") * 17, 15));


    Button opt1(" Yes", {strlen("Yes") * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    opt1.setFont(font1);
    opt1.setPositions(sf::Vector2f(window.getSize().x / 25 * 11, window.getSize().y / 7 * 4),
                      sf::Vector2f(strlen("Yes") * 17, 15));
    Button opt2(" No", {strlen("No") * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    opt2.setFont(font1);
    opt2.setPositions(sf::Vector2f(window.getSize().x / 20 * 11, window.getSize().y / 7 * 4),
                      sf::Vector2f(strlen("No") * 17, 15));

    Button done("   Done", {strlen("Done") * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    done.setFont(font1);
    done.setPositions(sf::Vector2f(window.getSize().x / 20 * 11, window.getSize().y / 7 * 4),
                      sf::Vector2f(strlen("Play") * 17, 15));

    Button go("   Go", {strlen("Go") * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    go.setFont(font1);
    go.setPositions(sf::Vector2f(window.getSize().x / 20 * 11, window.getSize().y / 7 * 4),
                    sf::Vector2f(strlen("Play") * 17, 15));

    Button VolumeDown("-", {strlen("-") * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    VolumeDown.setFont(font1);
    VolumeDown.setPositions(sf::Vector2f(window.getSize().x / 25 * 11, window.getSize().y / 100*47),
                      sf::Vector2f(strlen("-") * 5, 15));
    Button VolumeUp("+", {strlen("+") * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    VolumeUp.setFont(font1);
    VolumeUp.setPositions(sf::Vector2f(window.getSize().x / 20 * 11, window.getSize().y / 20 * 9),
                      sf::Vector2f(strlen("+") * 17, 15));


    Popup quit("Are you sure you\nwant to quit?", sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3), 50,
               sf::Color::Black, sf::Color(130,0,2,255));
    quit.setFont(font1);
    quit.setPosition(sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                  (window.getSize().y - window.getSize().y / 3) / 2),
                     sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                  (window.getSize().y - window.getSize().y / 3) / 2));
    std::cout<<quit<<"\n";
    Popup settings("Audio Level", sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3), 55, sf::Color::Black,
                   sf::Color(130,0,2,255));
    settings.setFont(font1);
    settings.setPosition(sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                      (window.getSize().y - window.getSize().y / 3) / 2),
                         sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                      (window.getSize().y - window.getSize().y / 3) / 2));
    Popup play("Enter your username:", sf::Vector2f(window.getSize().x / 3, window.getSize().y / 3), 55,
               sf::Color::Black, sf::Color(130,0,2,255));
    play.setFont(font1);
    play.setPosition(sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                  (window.getSize().y - window.getSize().y / 3) / 2),
                     sf::Vector2f((window.getSize().x - window.getSize().x / 3) / 2,
                                  (window.getSize().y - window.getSize().y / 3) / 2));
    Textbox textbox1(30,sf::Color::Yellow,true);
    textbox1.setFont(font1);
    textbox1.setPosition(sf::Vector2f(window.getSize().x / 25 * 11, window.getSize().y / 20 * 9));
    textbox1.setLimit(true,20);

    music.play();
    music.setLoop(true);
    music2.setLoop(true);
    music3.setLoop(true);
    int resp = 0;
    while (window.isOpen()) {
        deltaTime=clock.restart().asSeconds();
        window.clear();
        //window.draw(background);
        window.draw(animatedBackground);
        switch(resp){
            case 0:
                btn1.drawTo(window);
                btn2.drawTo(window);
                btn3.drawTo(window);
                window.display();
                break;
            case 1:
                quit.draw(window);
                opt1.drawTo(window);
                opt2.drawTo(window);
                window.display();
                break;
            case 2:
                settings.draw(window);
                VolumeUp.drawTo(window);
                VolumeDown.drawTo(window);
                done.drawTo(window);
                window.display();
                break;
            case 3:
                play.draw(window);
                textbox1.drawTo(window);
                go.drawTo(window);
                window.display();
                break;
            default:
                break;
        }


        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyReleased:
                    if(event.key.code==sf::Keyboard::Escape&&resp==0)
                        resp=1;
                    if(event.key.code==sf::Keyboard::Escape&&(resp==2||resp==3))
                        resp=0;
                    break;

                case sf::Event::TextEntered:
                    textbox1.typedOn(event);
                    break;
                case sf::Event::MouseMoved:
                    if (btn1.isMouseOver(window)) {
                        btn1.setTextColor(sf::Color(130,0,2,255));
                    } else
                        btn1.setTextColor(sf::Color(255,146,0,255));
                    if (btn2.isMouseOver(window)) {
                        btn2.setTextColor(sf::Color(130,0,2,255));
                    } else
                        btn2.setTextColor(sf::Color(255,146,0,255));
                    if (btn3.isMouseOver(window)) {
                        btn3.setTextColor(sf::Color(130,0,2,255));
                    } else
                        btn3.setTextColor(sf::Color(255,146,0,255));
                    if (opt1.isMouseOver(window)) {
                        opt1.setTextColor(sf::Color(130,0,2,255));
                    } else {
                        opt1.setTextColor(sf::Color(255,146,0,255));
                    }
                    if (opt2.isMouseOver(window)) {
                        opt2.setTextColor(sf::Color(130,0,2,255));
                    } else {
                        opt2.setTextColor(sf::Color(255,146,0,255));
                    }
                    if (done.isMouseOver(window)) {
                        done.setTextColor(sf::Color(130,0,2,255));
                    } else {
                        done.setTextColor(sf::Color(255,146,0,255));
                    }
                    if (go.isMouseOver(window)) {
                        go.setTextColor(sf::Color(130,0,2,255));
                    } else {
                        go.setTextColor(sf::Color(255,146,0,255));
                    }
                    if(VolumeDown.isMouseOver(window)){
                        VolumeDown.setTextColor(sf::Color(130,0,2,255));
                    }else{
                        VolumeDown.setTextColor(sf::Color(255,146,0,255));
                    }
                    if(VolumeUp.isMouseOver(window)){
                        VolumeUp.setTextColor(sf::Color(130,0,2,255));
                    }else{
                        VolumeUp.setTextColor(sf::Color(255,146,0,255));
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (go.isMouseOver(window) && resp == 3) {
                        window.clear();
                        window.draw(animatedBackground);
                        window.display();
                        std::string name=textbox1.getText();
                        player2.setName(name);
                        if(player2.getEnc()=="Yriv"){
                            music.pause();
                            music2.play();
                        }
                        if(player2.getEnc()=="Napn"){
                            music.pause();
                            music3.play();
                        }
                        if(player2.getEnc()=="Crgevfbe"){
                            music.pause();
                            //music4.play();
                        }
                        resp = 4;
                    }
                    if (opt1.isMouseOver(window) && resp == 1) {
                        window.close();
                        return 0;
                    }
                    if (opt2.isMouseOver(window) && resp == 1) {
                        resp = 0;
                        continue;
                    }
                    if (done.isMouseOver(window) && resp == 2) {
                        resp = 0;
                        continue;
                    }
                    if(VolumeDown.isMouseOver(window)&&resp == 2){
                        if(music.getVolume()<15) {
                            music.setVolume(0);
                            music2.setVolume(0);
                            music3.setVolume(0);
                        }else{
                            music.setVolume(music.getVolume()-10);
                            music2.setVolume(music.getVolume()-10);
                            music3.setVolume(music.getVolume()-10);
                        }
                        std::cout<<music.getVolume();
                    }
                    if(VolumeUp.isMouseOver(window)&&resp==2){
                        if (music.getVolume()<90) {
                            music.setVolume(music.getVolume() + 10);
                            music2.setVolume(music2.getVolume() + 10);
                            music3.setVolume(music3.getVolume() + 10);
                        }
                        //else if(music.getVolume()<10) {
                        //    music.setVolume(10);
                        //    music2.setVolume(10);
                        //    music3.setVolume(10);
                        //}
                        std::cout<<music.getVolume();
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
                    break;
                default:
                    //std::cout<<"Am intrat in default,boss\n";
                    break;
            }

        }
        animation.Update(0,deltaTime);
        animatedBackground.setTextureRect(animation.uvRect);
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