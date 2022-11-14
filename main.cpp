#include "Player.h"
#include <iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include "Button.h"
#include<cstring>
#include "Textbox.h"
#include "Animation.h"
#include "Entity.h"
#include "MainMenu.h"
#include "Resources.h"

namespace displaying
{
    enum options
    {
        MENU,
        PLAY,
        SETTINGS,
        QUIT,
        GAME
    };
}
class TextDisp{
private:
    sf::Text text;
    sf::Vector2f position;
    std::string txt;
public:
    TextDisp(const std::string &popupText, int charSize, sf::Color textColor): txt(popupText) {
        text.setString(txt);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
    }
    ~TextDisp() {
        //std::cout << "Am mai apelat un destructor\n";
    }

    std::string getText() const {
        return txt;
    }
    void setText(std::string &other){
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

    void draw(sf::RenderWindow &window) {
        window.draw(text);
    }
    friend std::ostream &operator<<(std::ostream &os, const TextDisp &textdisp);
};
class Popup {
private:
    sf::RectangleShape popup, shadow;
    sf::Text text;
    sf::Vector2f Position;
    std::string txt;
public:
    Popup(const std::string &popupText, sf::Vector2f popupSize, int charSize, sf::Color textColor,sf::Texture &texture): txt(popupText) {
        popup.setSize(popupSize);
        //popup.setFillColor(sf::Color::Black);
        //shadow.setSize(popupSize + sf::Vector2f(1, 1));
        //shadow.setFillColor(sf::Color::White);
        text.setString(txt);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(5);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
        popup.setTexture(&texture);
    }

    ~Popup() {
        //std::cout << "Am mai apelat un destructor\n";
    }

    std::string getText() const {
        return txt;
    }
    [[maybe_unused]] void setCharSize(int c) {
        text.setCharacterSize(c);
        //shadow.setCharacterSize(c + 2);
    }
    //void setTexture(const sf::Texture &texture){
    //    popup.setTexture(texture);
    //}
    void setFont(sf::Font &fonts) {
        text.setFont(fonts);
        //shadow.setFont(fonts);
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

    friend std::ostream &operator<<(std::ostream &os, const Popup &popup);
};

std::ostream &operator<<(std::ostream &os, const Popup &popup) {
    os << "A fost generat popup-ul cu textul: " << popup.getText() << "\n";
    return os;
}
std::ostream &operator<<(std::ostream &os, const TextDisp &textdisp) {
    os << "A fost generat textul: " << textdisp.getText() << "\n";
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
    Entity Pac(static_cast<float>(window.getSize().x) / 8, static_cast<float>(window.getSize().y) / 8);

    //MainMenu menu();


    //Amimated Background
    sf::RectangleShape animatedBackground(sf::Vector2f(1920,1080));
    animatedBackground.setPosition(0,0);


    animatedBackground.setTexture(&Resources::animatedBackground);
    Animation animation(&Resources::animatedBackground,sf::Vector2u(8,1),0.15f);
    sf::Clock clock;

    //Sound
    sf::Music music, music2, music3, music5;
    music.openFromFile("resources/GameMusic.flac");
    music2.openFromFile("resources/Music2.flac");
    music3.openFromFile("resources/Music3.flac");
    music5.openFromFile("resources/Music5.flac");

    //music.setVolume(10);
    for (const auto &it: {&music,&music2,&music3,&music5}){
        it->setVolume(0);
        it->setLoop(true);
    }




    Button btn1("   Play", {static_cast<float>(strlen("Play")) * 30.f, 30.f}, 77, sf::Color::Transparent,
                sf::Color(130,0,2,255));//, sf::Sound sound1);
    btn1.setFont(Resources::defaultFont);
    btn1.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x)/ 8 * 6, static_cast<float>(window.getSize().y) * 55 / 100),
                      sf::Vector2f(static_cast<float>(strlen("Play") * 17), 15));
    std::cout << btn1;

    Button btn2("     Settings", {static_cast<float>(strlen("Settings")) * 30.f, 30.f}, 77, sf::Color::Transparent,
                sf::Color(130,0,2,255));//,sf::Sound sound1);
    btn2.setFont(Resources::defaultFont);
    btn2.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x) / 8 * 6, static_cast<float>(window.getSize().y) * 70 / 100),
                      sf::Vector2f(static_cast<float>(strlen("Settings") * 17), 15));


    Button btn3("   Quit", {static_cast<float>(strlen("Quit")) * 30.f, 30.f}, 77, sf::Color::Transparent,
                sf::Color(130,0,2,255));//,sf::Sound sound1);
    btn3.setFont(Resources::defaultFont);
    btn3.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x) / 8 * 6, static_cast<float>(window.getSize().y) * 85 / 100),
                      sf::Vector2f(static_cast<float>(strlen("Quit") * 17), 15));


    Button opt1(" Yes", {static_cast<float>(strlen("Yes")) * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    opt1.setFont(Resources::defaultFont);
    opt1.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x) / 25 * 11, static_cast<float>(window.getSize().y) / 7 * 4),
                      sf::Vector2f(static_cast<float>(strlen("Yes")) * 17, 15));
    Button opt2(" No", {static_cast<float>(strlen("No")) * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    opt2.setFont(Resources::defaultFont);
    opt2.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4),
                      sf::Vector2f(static_cast<float>(strlen("No")) * 17, 15));

    Button done("   Done", {static_cast<float>(strlen("Done")) * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    done.setFont(Resources::defaultFont);
    done.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4),
                      sf::Vector2f(static_cast<float>(strlen("Play")) * 17, 15));

    Button go("   Go", {static_cast<float>(strlen("Go")) * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    go.setFont(Resources::defaultFont);
    go.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4),
                    sf::Vector2f(static_cast<float>(strlen("Play")) * 17, 15));

    Button VolumeDown("-", {static_cast<float>(strlen("-")) * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    VolumeDown.setFont(Resources::defaultFont);
    VolumeDown.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x) / 25 * 11, static_cast<float>(window.getSize().y) / 100 * 43),
                      sf::Vector2f(static_cast<float>(strlen("-")) * 5, 15));
    Button VolumeUp("+", {static_cast<float>(strlen("+")) * 30.f, 30.f}, 77, sf::Color::Transparent, sf::Color::Yellow);
    VolumeUp.setFont(Resources::defaultFont);
    VolumeUp.setPositions(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 20 * 9),
                      sf::Vector2f(static_cast<float>(strlen("+")) * 17, 15));


    Popup quit("  Are you sure you\n  want to quit?", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 50, //sf::Color::Black,
                sf::Color(130,0,2,255),Resources::popupWindow);
    quit.setFont(Resources::defaultFont);
    quit.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                  (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                     sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                  (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));
    std::cout<<quit<<"\n";
    Popup settings("  Audio Level", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 55, //sf::Color::Black,
                   sf::Color(130,0,2,255),Resources::popupWindow);
    settings.setFont(Resources::defaultFont);
    settings.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                         sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));

    std::string soundL=std::to_string(static_cast<int>(music.getVolume()+0.1));
    soundL=soundL.substr(0,2);
    TextDisp soundlevel(soundL,45,sf::Color(130,0,2,255));
    soundlevel.setFont(Resources::defaultFont);
    soundlevel.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 200*97, static_cast<float>(window.getSize().y) / 20 * 9));

    Popup play("  Enter your username:", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 55, //sf::Color::Black,
                sf::Color(130,0,2,255),Resources::popupWindow);
    play.setFont(Resources::defaultFont);
    play.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                  (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                     sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                  (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));
    Textbox textbox1(30,sf::Color::Yellow,true);
    textbox1.setFont(Resources::defaultFont);
    textbox1.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 25 * 11, static_cast<float>(window.getSize().y) / 20 * 9));
    textbox1.setLimit(true,12);

    music.play();


    displaying::options scenario=displaying::MENU;


    while (window.isOpen()) {
        const float deltaTime=clock.restart().asSeconds();
        window.clear();
        window.draw(animatedBackground);
        switch(scenario){
            case displaying::MENU:
                btn1.drawTo(window);
                btn2.drawTo(window);
                btn3.drawTo(window);
                break;
            case displaying::QUIT:
                quit.draw(window);
                opt1.drawTo(window);
                opt2.drawTo(window);
                break;
            case displaying::SETTINGS:
                settings.draw(window);
                VolumeUp.drawTo(window);
                VolumeDown.drawTo(window);
                soundlevel.draw(window);
                done.drawTo(window);
                break;
            case displaying::PLAY:
                play.draw(window);
                textbox1.drawTo(window);
                go.drawTo(window);
                break;
            case displaying::GAME:
                Pac.drawTo(window);
                //std::cout<<"Case4\n";
                break;
            default:
                break;
        }
        window.display();

        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    Pac.processEvents(event.key.code,true);
                    Pac.update();
                case sf::Event::KeyReleased:
                    Pac.processEvents(event.key.code,false);
                    Pac.update();
                    if(event.key.code==sf::Keyboard::Escape&&scenario==displaying::GAME)
                        scenario=displaying::QUIT;
                    if(event.key.code==sf::Keyboard::Escape&&(scenario==displaying::SETTINGS||scenario==displaying::PLAY))
                        scenario=displaying::MENU;
                    break;

                case sf::Event::TextEntered:
                    textbox1.typedOn(event);
                    break;
                case sf::Event::MouseMoved:
                    for (const auto &it: {&btn1,&btn2,&btn3,&opt1, &opt2, &done, &go, &VolumeDown, &VolumeUp}){
                        if (it->isMouseOver(window)) {
                            it->setTextColor(sf::Color(130, 0, 2, 255));
                        } else
                            it->setTextColor(sf::Color(255, 146, 0, 255));
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (go.isMouseOver(window) && scenario==displaying::PLAY) {
                        window.clear();
                        window.draw(animatedBackground);
                        window.display();

                        std::string name=textbox1.getText();
                        player2.setName(name);
                        if(player2.getEnc()=="yriv"){
                            music.pause();
                            music2.play();
                        }
                        if(player2.getEnc()=="napn"){
                            music.pause();
                            music3.play();
                            std::cout<<music3.getVolume();
                        }
                        if(player2.getEnc()=="prgevfbe"){
                            music.pause();
                            //music4.play();
                        }
                        if(player2.getEnc()=="znevhf"){
                            music.pause();
                            music5.play();
                        }
                        scenario=displaying::GAME;
                    }
                    if (opt1.isMouseOver(window) && scenario==displaying::QUIT) {
                        window.close();
                        return 0;
                    }
                    if (opt2.isMouseOver(window) && scenario==displaying::QUIT) {
                        scenario=displaying::MENU;
                        continue;
                    }
                    if (done.isMouseOver(window) && scenario==displaying::SETTINGS) {
                        scenario=displaying::MENU;
                        continue;
                    }
                    if(VolumeDown.isMouseOver(window) && scenario==displaying::SETTINGS){
                        if(music.getVolume()<15) {
                            for (const auto &it: {&music,&music2,&music3,&music5}){
                                it->setVolume(0);
                            }
                        }else{
                            for (const auto &it: {&music,&music2,&music3,&music5}){
                                it->setVolume(it->getVolume()-10);
                            }
                        }
                        soundL=std::to_string(static_cast<int>(music.getVolume()+0.1));
                        soundL=soundL.substr(0,2);
                        soundlevel.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 200*97, static_cast<float>(window.getSize().y) / 20 * 9));
                        soundlevel.setText(soundL);
                    }
                    if(VolumeUp.isMouseOver(window) && scenario==displaying::SETTINGS){
                        if (music.getVolume()<90) {
                            for (const auto &it: {&music,&music2,&music3,&music5}){
                                it->setVolume(it->getVolume() + 10);
                            }
                        }
                        soundL=std::to_string(static_cast<int>(music.getVolume()+0.1));
                        soundL=soundL.substr(0,2);
                        if(100-music.getVolume()<5){
                            soundlevel.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 100*48, static_cast<float>(window.getSize().y) / 20 * 9));
                            soundL="100";
                        }
                        soundlevel.setText(soundL);
                    }
                    if (btn3.isMouseOver(window) && scenario==displaying::MENU) {
                        scenario=displaying::QUIT;
                    }
                    if (btn2.isMouseOver(window) && scenario==displaying::MENU) {
                        scenario=displaying::SETTINGS;
                    }
                    if (btn1.isMouseOver(window) && scenario==displaying::MENU) {
                        scenario=displaying::PLAY;
                    }
                    break;
                default:
                    break;
            }
        }
        animation.Update(0,deltaTime);
        animatedBackground.setTextureRect(animation.getuvRect());
    }
    return 0;
}