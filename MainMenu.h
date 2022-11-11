//
// Created by Matei on 11/11/2022.
//
#include <iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#ifndef OOP_MAINMENU_H
#define OOP_MAINMENU_H


class MainMenu {
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    void initVariables();
    void initWindow();
public:
    MainMenu();
    virtual ~MainMenu();
    const bool running() const;
    void update();
    void render();
};


#endif //OOP_MAINMENU_H
