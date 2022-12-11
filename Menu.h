#pragma once
#ifndef OOP_MENU_H
#define OOP_MENU_H
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include "Button.h"
#include "Textbox.h"
#include "Animation.h"
#include "Entity.h"
#include "Resources.h"
#include "TextDisp.h"
#include "Popup.h"
#include "Player.h"
#include "Map.h"

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
std::vector<std::string> map_sketch = {
        " ################### ",
        " #........#........# ",
        " #o##.###.#.###.##o# ",
        " #.................# ",
        " #.##.#.#####.#.##.# ",
        " #....#...#...#....# ",
        " ####.### # ###.#### ",
        "    #.#   0   #.#    ",
        "#####.# ##=## #.#####",
        "     .  #123#  .     ",
        "#####.# ##### #.#####",
        "    #.#       #.#    ",
        " ####.# ##### #.#### ",
        " #........#........# ",
        " #.##.###.#.###.##.# ",
        " #o.#.....P.....#.o# ",
        " ##.#.#.#####.#.#.## ",
        " #....#...#...#....# ",
        " #.######.#.######.# ",
        " #.................# ",
        " ################### "
};

class Menu {
private:
    sf::RenderWindow window;
    sf::Event event;
    sf::RectangleShape animatedBackground;
    sf::Clock clock;
    Animation animation1;
    Button btn1,btn2,btn3,opt1,opt2,done,go,VolumeDown,VolumeUp;
    Popup quit,settings,play;
    displaying::options scenario=displaying::MENU;
    Textbox textbox1;
    Entity Pac;

    Player player2;
    sf::Music music, music2, music3, music5;
    std::string soundL;
    TextDisp soundlevel;
    Map map;

    void initWindow(){
        player2.setBestScore(0);
        player2.setName("Podi");
        player2.setTime(0);
        this->window.create(sf::VideoMode::getDesktopMode(), "Pac-Man ILMF",sf::Style::Fullscreen);
        map.Innit(map_sketch.size(),window.getSize().y,window.getSize().x,map_sketch);
        Pac.Innit(static_cast<float>(window.getSize().y) / 22, static_cast<float>(window.getSize().y) / 22);
        animatedBackground.setSize(sf::Vector2f(1920,1080));
        animatedBackground.setPosition(0,0);
        animatedBackground.setTexture(&Resources::animatedBackground);
        animation1.Innit(&Resources::animatedBackground,sf::Vector2u(8,1),0.15f);
        btn1.Innit("Play", 77,Resources::defaultFont);
        btn1.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x)/ 8 * 6, static_cast<float>(window.getSize().y) * 55 / 100));
        btn2.Innit("Settings", 77,Resources::defaultFont);
        btn2.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 8 * 6, static_cast<float>(window.getSize().y) * 70 / 100));
        btn3.Innit("Quit", 77,Resources::defaultFont);//,sf::Sound sound1);
        btn3.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 8 * 6, static_cast<float>(window.getSize().y) * 85 / 100));
        opt1.Innit("Yes", 77,Resources::defaultFont);
        opt1.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 25 * 11, static_cast<float>(window.getSize().y) / 7 * 4));
        opt2.Innit("No", 77,Resources::defaultFont);
        opt2.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));
        done.Innit("Done", 77,Resources::defaultFont);
        done.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));
        go.Innit("Go", 77,Resources::defaultFont);
        go.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));
        VolumeDown.Innit("-", 77,Resources::defaultFont);
        VolumeDown.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 26 * 11, static_cast<float>(window.getSize().y) / 100*47));
        VolumeUp.Innit("+", 77,Resources::defaultFont);
        VolumeUp.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 100*47));
        play.Innit("  Enter your username:", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 55,
                sf::Color(130,0,2,255),Resources::popupWindow,Resources::defaultFont);
        play.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                         sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));
        settings.Innit("  Audio Level", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 55,
                       sf::Color(130,0,2,255),Resources::popupWindow,Resources::defaultFont);
        settings.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                          (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                             sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                          (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));
        quit.Innit("  Are you sure you\n  want to quit?", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 50,
                   sf::Color(130,0,2,255),Resources::popupWindow,Resources::defaultFont);
        quit.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                         sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));
        textbox1.Innit(30,sf::Color::Yellow,true);
        textbox1.setFont(Resources::defaultFont);
        textbox1.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 25 * 11, static_cast<float>(window.getSize().y) / 20 * 9));
        textbox1.setLimit(true,12);
        music.openFromFile("resources/GameMusic.flac");
        music2.openFromFile("resources/Music2.flac");
        music3.openFromFile("resources/Music3.flac");
        music5.openFromFile("resources/Music5.flac");
        for (const auto &it: {&music,&music2,&music3,&music5}){
            it->setVolume(0);
            it->setLoop(true);
        }
        soundL=std::to_string(static_cast<int>(music.getVolume()+0.1));
        soundL.resize(1);
        soundlevel.Innit(soundL,45,sf::Color(130,0,2,255));
        soundlevel.setFont(Resources::defaultFont);
        soundlevel.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 200*97, static_cast<float>(window.getSize().y) / 20 * 9));
        music.play();
    }
public:
    Menu(){
        initWindow();
    };
    ~Menu()=default;

    void update(){
        const float deltaTime=clock.restart().asSeconds();
        while(this->window.pollEvent(this->event)){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    Pac.processEvents(event.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    Pac.processEvents(event.key.code, false);

                    if (event.key.code == sf::Keyboard::Escape && scenario == displaying::GAME)
                        scenario = displaying::QUIT;
                    if (event.key.code == sf::Keyboard::Escape &&
                        (scenario == displaying::SETTINGS || scenario == displaying::PLAY))
                        scenario = displaying::MENU;
                    break;
                case sf::Event::TextEntered:
                    textbox1.typedOn(event);
                    break;
                case sf::Event::MouseMoved:
                    for (const auto &it: {&btn1, &btn2, &btn3, &opt1, &opt2, &done, &go, &VolumeDown, &VolumeUp}) {
                        if (it->isMouseOver(window)) {
                            it->setTextColor(sf::Color(130, 0, 2, 255));
                        } else
                            it->setTextColor(sf::Color(255, 146, 0, 255));
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (go.isMouseOver(window) && scenario == displaying::PLAY) {
                        std::string name = textbox1.getText();
                        player2.setName(name);
                        try {
                            if(!name.length())
                                throw name.length();
                        }
                        catch (int x) {
                            std::cout<<"Please enter a name with more than "<<x<<" letters";
                            continue;
                        }
                        window.clear();
                        window.display();


                        if (player2.getEnc() == 4201227126) {
                            music.pause();
                            music2.play();
                        }
                        if (player2.getEnc() == 4200760982) {
                            music.pause();
                            music3.play();
                            std::cout << music3.getVolume();
                        }
                        if (player2.getEnc() == 4195453816) {
                            music.pause();
                            //music4.play();
                        }
                        if (player2.getEnc() == 4193874688) {
                            music.pause();
                            music5.play();
                        }
                        Pac.setPosition(map.getPac_pos());
                        scenario = displaying::GAME;
                    }
                    if (opt1.isMouseOver(window) && scenario == displaying::QUIT) {
                        window.close();
                    }
                    if (opt2.isMouseOver(window) && scenario == displaying::QUIT) {
                        scenario = displaying::MENU;
                        continue;
                    }
                    if (done.isMouseOver(window) && scenario == displaying::SETTINGS) {
                        scenario = displaying::MENU;
                        continue;
                    }
                    if (VolumeDown.isMouseOver(window) && scenario == displaying::SETTINGS) {
                        if (music.getVolume() < 15) {
                            for (const auto &it: {&music, &music2, &music3, &music5}) {
                                it->setVolume(0);
                            }
                            soundL = std::to_string(static_cast<int>(music.getVolume() + 0.1));
                            soundL.resize(1);
                        } else {
                            for (const auto &it: {&music, &music2, &music3, &music5}) {
                                it->setVolume(it->getVolume() - 10);
                            }
                            soundL = std::to_string(static_cast<int>(music.getVolume() + 0.1));
                            soundL.resize(2);
                        }
                        soundlevel.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 200 * 97,
                                                            static_cast<float>(window.getSize().y) / 20 * 9));
                        soundlevel.setText(soundL);
                    }
                    if (VolumeUp.isMouseOver(window) && scenario == displaying::SETTINGS) {
                        if (music.getVolume() < 90) {
                            for (const auto &it: {&music, &music2, &music3, &music5}) {
                                it->setVolume(it->getVolume() + 10);
                            }
                        }
                        soundL = std::to_string(static_cast<int>(music.getVolume() + 0.1));
                        soundL.resize(2);
                        if (100 - music.getVolume() < 5) {
                            soundlevel.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 100 * 48,
                                                                static_cast<float>(window.getSize().y) / 20 * 9));
                            soundL = "100";
                        }
                        soundlevel.setText(soundL);
                    }
                    if (btn3.isMouseOver(window) && scenario == displaying::MENU) {
                        scenario = displaying::QUIT;
                    }
                    if (btn2.isMouseOver(window) && scenario == displaying::MENU) {
                        scenario = displaying::SETTINGS;
                    }
                    if (btn1.isMouseOver(window) && scenario == displaying::MENU) {
                        scenario = displaying::PLAY;
                    }
                    break;
                default:
                    break;
            }
        }
        animation1.Update(0,deltaTime);
        animatedBackground.setTextureRect(animation1.getuvRect());
        Pac.update(deltaTime,map.getWalls());
    };
    void render() {
        this->window.clear();
        this->window.draw(animatedBackground);
        switch(scenario){
            case displaying::MENU:
                btn1.draw(window);
                btn2.draw(window);
                btn3.draw(window);
                break;
            case displaying::QUIT:
                quit.draw(window);
                opt1.draw(window);
                opt2.draw(window);
                break;
            case displaying::SETTINGS:
                settings.draw(window);
                VolumeUp.draw(window);
                VolumeDown.draw(window);
                soundlevel.draw(window);
                done.draw(window);
                break;
            case displaying::PLAY:
                play.draw(window);
                textbox1.drawTo(window);
                go.draw(window);
                break;
            case displaying::GAME:
                map.drawTo(window);
                Pac.drawTo(window);
                break;
            default:
                break;
        }
        this->window.display();
    };
    const sf::RenderWindow& getWindow() const{
        return this->window;
    };
};

#endif //OOP_MENU_H
