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
#include "PopupFactory.h"


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
    Button btn1{"Play", 77,Resources::defaultFont},\
    btn2{"Settings", 77,Resources::defaultFont,},\
    btn3{"Quit", 77,Resources::defaultFont},\
    opt1{"Yes", 77,Resources::defaultFont},\
    opt2{"No", 77, Resources::defaultFont},\
    done{"Done", 77,Resources::defaultFont},\
    go{"Go", 77,Resources::defaultFont},\
    VolumeDown{"-", 77,Resources::defaultFont},\
    VolumeUp{"+", 77,Resources::defaultFont};
    Popup quit=PopupFactory::simplePopup("  Are you sure you\n  want to quit?",window);
    Popup settings=PopupFactory::simplePopup("  Audio Level",window);
    Popup play=PopupFactory::simplePopup("  Enter your username:",window);
    displaying::options scenario=displaying::MENU;
    Textbox textbox1{30,sf::Color::Yellow,true,Resources::defaultFont};

    Player player;
    sf::Music music, music2, music3, music5;
    std::string soundL;
    TextDisp soundlevel{soundL,45,sf::Color(130,0,2,255),Resources::defaultFont,sf::Vector2f(static_cast<float>(window.getSize().x) / 200*97, static_cast<float>(window.getSize().y) / 20 * 9)};
    TextDisp score{"0",45,sf::Color(130,0,2,255),Resources::defaultFont,sf::Vector2f(0,0)};
    Map map;
    int Scor=0,normalPoints=0,PowerPoints=0;
    float Sidebar=0;
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<sf::Texture> colors;
    std::vector<sf::Vector2f> GhostPos;
    Menu();
public:
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;

    void update();
    const sf::RenderWindow& getWindow() const;
    void render();
    static bool Lost(const std::vector<std::shared_ptr<Entity>> &entitiess,sf::Vector2f Pos);
    static Menu& get_menu();
};

#endif //OOP_MENU_H
