#include "Player.h"
#include <iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include "Button.h"
#include "Textbox.h"
#include "Animation.h"
#include "Entity.h"
#include "Resources.h"
#include "TextDisp.h"
#include "Popup.h"

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



int main() {

    Player player2("Matei");
    player2.setBestScore(0);
    player2.setName("Podi");
    player2.setTime(0);
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




    Button btn1("   Play", 77,Resources::defaultFont);//, sf::Sound sound1);
    //btn1.setFont(Resources::defaultFont);
    btn1.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x)/ 8 * 6, static_cast<float>(window.getSize().y) * 55 / 100));//,sf::Vector2f(static_cast<float>(strlen("Play") * 17), 15));

    Button btn2("     Settings", 77,Resources::defaultFont);//,sf::Sound sound1);
    //btn2.setFont(Resources::defaultFont);
    btn2.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 8 * 6, static_cast<float>(window.getSize().y) * 70 / 100));//,sf::Vector2f(static_cast<float>(strlen("Settings") * 17), 15));


    Button btn3("   Quit", 77,Resources::defaultFont);//,sf::Sound sound1);
    //btn3.setFont(Resources::defaultFont);
    btn3.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 8 * 6, static_cast<float>(window.getSize().y) * 85 / 100));//,sf::Vector2f(static_cast<float>(strlen("Quit") * 17), 15));


    Button opt1(" Yes", 77,Resources::defaultFont);
    //opt1.setFont(Resources::defaultFont);
    opt1.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 25 * 11, static_cast<float>(window.getSize().y) / 7 * 4));//,sf::Vector2f(static_cast<float>(strlen("Yes")) * 17, 15));
    Button opt2(" No", 77,Resources::defaultFont);
    //opt2.setFont(Resources::defaultFont);
    opt2.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));//,sf::Vector2f(static_cast<float>(strlen("No")) * 17, 15));

    Button done("   Done", 77,Resources::defaultFont);
    //done.setFont(Resources::defaultFont);
    done.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));//,sf::Vector2f(static_cast<float>(strlen("Play")) * 17, 15));

    Button go("   Go", 77,Resources::defaultFont);
    //go.setFont(Resources::defaultFont);
    go.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 7 * 4));//,sf::Vector2f(static_cast<float>(strlen("Play")) * 17, 15));

    Button VolumeDown("-", 77,Resources::defaultFont);
    //VolumeDown.setFont(Resources::defaultFont);
    VolumeDown.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 25 * 11, static_cast<float>(window.getSize().y) / 100 * 43));//,sf::Vector2f(static_cast<float>(strlen("-")) * 5, 15));
    Button VolumeUp("+", 77,Resources::defaultFont);
    //VolumeUp.setFont(Resources::defaultFont);
    VolumeUp.setPosition(sf::Vector2f(static_cast<float>(window.getSize().x) / 20 * 11, static_cast<float>(window.getSize().y) / 20 * 9));//,sf::Vector2f(static_cast<float>(strlen("+")) * 17, 15));


    Popup quit("  Are you sure you\n  want to quit?", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 50, //sf::Color::Black,
                sf::Color(130,0,2,255),Resources::popupWindow);
    quit.setFont(Resources::defaultFont);
    quit.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                  (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                     sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                  (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));

    Popup settings("  Audio Level", sf::Vector2f(static_cast<float>(window.getSize().x) / 3, static_cast<float>(window.getSize().y) / 3), 55, //sf::Color::Black,
                   sf::Color(130,0,2,255),Resources::popupWindow);
    settings.setFont(Resources::defaultFont);
    settings.setPosition(sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2),
                         sf::Vector2f((static_cast<float>(window.getSize().x) - static_cast<float>(window.getSize().x) / 3) / 2,
                                      (static_cast<float>(window.getSize().y) - static_cast<float>(window.getSize().y) / 3) / 2));

    std::string soundL=std::to_string(static_cast<int>(music.getVolume()+0.1));
    soundL.resize(1);
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
                Pac.update(window);
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

                    break;
                case sf::Event::KeyReleased:
                    Pac.processEvents(event.key.code,false);

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
                        if(player2.getEnc()==4201227126){
                            music.pause();
                            music2.play();
                        }
                        if(player2.getEnc()==4200760982){
                            music.pause();
                            music3.play();
                            std::cout<<music3.getVolume();
                        }
                        if(player2.getEnc()==4195453816){
                            music.pause();
                            //music4.play();
                        }
                        if(player2.getEnc()==4193874688){
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
                            soundL=std::to_string(static_cast<int>(music.getVolume()+0.1));
                            soundL.resize(1);
                        }else{
                            for (const auto &it: {&music,&music2,&music3,&music5}){
                                it->setVolume(it->getVolume()-10);
                            }
                            soundL=std::to_string(static_cast<int>(music.getVolume()+0.1));
                            soundL.resize(2);
                        }
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
                        soundL.resize(2);
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