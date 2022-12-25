#pragma once
#ifndef OOP_MENU_H
#define OOP_MENU_H
#include<iostream>
#include <memory>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include "Button.h"
#include "Textbox.h"
#include "Animation.h"
#include "Resources.h"
#include "TextDisp.h"
#include "Popup.h"
#include "Player.h"
#include "Map.h"
#include "Pacman.h"
#include "Ghosts.h"

namespace displaying
{
    enum options
    {
        MENU,
        PLAY,
        SETTINGS,
        QUIT,
        GAME,
        WON,
        LOST,
    };
}

class Menu {
private:
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
    sf::RenderWindow window{sf::VideoMode::getDesktopMode(),"Pac-Man ILMF",sf::Style::Fullscreen};
    sf::Event event;
    sf::RectangleShape animatedBackground;
    sf::Clock clock;
    Animation animation1{&Resources::animatedBackground,sf::Vector2u(8,1),0.15f};
    Button btn1{"Play", 77,Resources::defaultFont},btn2{"Settings", 77,Resources::defaultFont},btn3{"Quit", 77,Resources::defaultFont},\
    opt1{"Yes", 77,Resources::defaultFont},opt2{"No", 77, Resources::defaultFont},done{"Done", 77,Resources::defaultFont},\
    go{"Go", 77,Resources::defaultFont},VolumeDown{"-", 77,Resources::defaultFont},VolumeUp{"+", 77,Resources::defaultFont};
    Popup quit{"  Are you sure you\n  want to quit?", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 50,
               sf::Color(130,0,2,255),Resources::popupWindow,Resources::defaultFont},\
    settings{"  Audio Level", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 55,
             sf::Color(130,0,2,255),Resources::popupWindow,Resources::defaultFont},\
                        play{"  Enter your username:", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 55,
                             sf::Color(130,0,2,255),Resources::popupWindow,Resources::defaultFont};
    displaying::options scenario=displaying::MENU;
    Textbox textbox1{30,sf::Color::Yellow,true,Resources::defaultFont};

    Player player;
    sf::Music music, music2, music3, music5;
    std::string soundL;
    TextDisp soundlevel{soundL,45,sf::Color(130,0,2,255),Resources::defaultFont},score{"0",45,sf::Color(130,0,2,255),Resources::defaultFont};
    Map map;
    int Scor=0,normalPoints=0,PowerPoints=0;
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<sf::Texture> colors;
    std::vector<sf::Vector2f> GhostPos;
    Menu(){
//        if(window.getSize().y>window.getSize().x){
//            throw ResolutionUnsupported("Your current screen resolution is not supported");
//        }
        window.setVerticalSyncEnabled(true);
        animatedBackground.setSize(sf::Vector2f(static_cast<float>(window.getSize().x),static_cast<float>(window.getSize().y)));
        animatedBackground.setPosition(0,0);
        animatedBackground.setTexture(&Resources::animatedBackground);
        btn1.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x)/ 8 * 6, static_cast<float>(window.getSize().y) * 55 / 100));
        btn2.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 8 * 6, static_cast<float>(window.getSize().y) * 70 / 100));
        btn3.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 8 * 6, static_cast<float>(window.getSize().y) * 85 / 100));
        opt1.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 25 * 11, static_cast<float>(window.getSize().y) / 7 * 4));
        opt2.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));
        done.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));
        go.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));
        VolumeDown.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 26 * 11, static_cast<float>(window.getSize().y) / 100*47));
        VolumeUp.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 100*47));
        play.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                         sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));
        settings.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                          (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                             sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                          (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));
        quit.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                         sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));
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
        music.play();
        soundlevel.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 200*97, static_cast<float>(window.getSize().y) / 20 * 9));
        colors.emplace_back(sf::Texture());
        colors.back()=Resources::BlueG;
        colors.emplace_back(sf::Texture());
        colors.back()=Resources::RedG;
        colors.emplace_back(sf::Texture());
        colors.back()=Resources::OrangeG;
        colors.emplace_back(sf::Texture());
        colors.back()=Resources::PinkG;
    };
public:
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    static Menu& get_menu() {
        static Menu menu;
        return menu;
    }

    void update(){
        const float deltaTime=clock.restart().asSeconds();
        while(this->window.pollEvent(this->event)){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape && scenario == displaying::GAME)
                        scenario = displaying::QUIT;
                    if (event.key.code == sf::Keyboard::Escape &&
                        (scenario == displaying::SETTINGS || scenario == displaying::PLAY))
                        scenario = displaying::MENU;
                    break;
                case sf::Event::KeyReleased:
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
                        try{
                            player=Player(name);
                            if (player.getEnc() == 4201227126) {
                                music.pause();
                                music2.play();
                            }
                            if (player.getEnc() == 4200760982) {
                                music.pause();
                                music3.play();
                            }
                            if (player.getEnc() == 4195453816) {
                                music.pause();
                            }
                            if (player.getEnc() == 4193874688) {
                                music.pause();
                                music5.play();
                            }
                            map.Innit(static_cast<int>(map_sketch.size()),static_cast<int>(window.getSize().y),static_cast<int>(window.getSize().x),map_sketch);
                            entities.push_back(std::make_shared<Pacman>(window.getSize().y/map_sketch.size(),window.getSize().y/map_sketch.size()));
                            entities.back()->setPosition(map.getPac_pos());
                            GhostPos=map.getGhost_pos();
                            for(int i=0;i<static_cast<int>(GhostPos.size());i++){
                                entities.push_back(std::make_shared<Ghosts>(window.getSize().y/map_sketch.size(),window.getSize().y/map_sketch.size(),colors[i]));
                                entities.back()->setPosition(GhostPos[i]);
                            }
                            normalPoints=static_cast<int>(map.getPoints().size());
                            PowerPoints=static_cast<int>(map.getPowerup().size());
                            scenario = displaying::GAME;
                        }
                        catch(InvalidNameError &){
                            std::cout<<"You need to enter a valid username before starting the game\n";
                        }
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
        Scor=(normalPoints-map.getPoints().size())*10+(PowerPoints-map.getPowerup().size())*30;
        score.setText(std::to_string(Scor));
        score.setPosition(sf::Vector2f(0,0));
        if(scenario==displaying::GAME){
            sf::Vector2f Pos;
            for(const auto&entity:entities){
                entity->handleMovement(map.getWalls());
                entity->move(map.getPoints(),map.getPowerup(),map_sketch,window.getSize().x);
                entity->update2(deltaTime);
                if(std::dynamic_pointer_cast<Pacman>(entity))
                    Pos=entity->GetPosition();
            }
            if(Lost(entities,Pos))
                scenario=displaying::LOST;
            if(map.getPoints().empty()&&map.getPowerup().empty())
                scenario=displaying::WON;
        }
    };
    static bool Lost(const std::vector<std::shared_ptr<Entity>> &entitiess,sf::Vector2f Pos){
        for(const auto&entity:entitiess) {
            if(std::dynamic_pointer_cast<Ghosts>(entity)&&entity->GetGlobalBounds().contains(Pos))
                return true;
        }
        return false;
    }
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
                for(const auto&entity:entities){
                    entity->drawTo(window);
                }
                score.draw(window);
                break;
            case displaying::WON:
                map.drawTo(window);
                for(const auto&entity:entities){
                    entity->drawTo(window);
                }
                score.draw(window);
                std::cout<<"Ai castigat\n";
                break;
            case displaying::LOST:
                std::cout<<"Ai pierdut\n";
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
