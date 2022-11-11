//
// Created by Matei on 11/11/2022.
//

#include "MainMenu.h"
void MainMenu::initVariables() {
    this->window=nullptr;
}
void MainMenu::initWindow() {
    //this->videoMode.height=1080;
    //this->videoMode.width=1920;
    this->videoMode.getDesktopMode();
    this->window=new sf::RenderWindow(this->videoMode,"Game 1",sf::Style::Fullscreen);
}
MainMenu::MainMenu() {
    this->initVariables();
    this->initWindow();
}
MainMenu::~MainMenu() {
    delete this->window;
}
const bool MainMenu::running() const {
    return this->window->isOpen();
}
void MainMenu::update() {

}
void MainMenu::render() {

}