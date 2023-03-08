#ifndef OOP_MAP_H
#define OOP_MAP_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include <vector>
#include "Resources.h"

class Map {
    std::vector<sf::RectangleShape> wall;
    std::vector<sf::CircleShape> point,powerup;
    sf::RectangleShape gate,background;
    sf::Vector2f Size,Pac_pos,Size2,Start_Pos;
    std::vector<sf::Vector2f> Ghost_pos;
    float sidebar=0;
public:
    Map()=default;
    void Innit(const int Map_Height,const int Screen_Height,const int Screen_Width,std::vector<std::string> map_sketch) {
        Size.x = Screen_Height / Map_Height;
        Size.y = Screen_Height / Map_Height;
        Size2.x = Size.x;
        Size2.y = Size.y / 3;
        sidebar = (Screen_Width - Size.x * map_sketch.size()) / 2;
        background.setFillColor(sf::Color::Black);
        background.setPosition(sf::Vector2f(sidebar,0));
        background.setSize(sf::Vector2f(Size.x*map_sketch.size(),Screen_Height));
        int n = static_cast<int>(map_sketch.size());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                switch (map_sketch[j][i]) {
                    case '#':
                        wall.emplace_back(sf::RectangleShape());
                        wall.back().setSize(Size);
                        wall.back().setPosition(sidebar + i * Size.x, j * Size.y);
                        wall.back().setTexture(&Resources::wall);
                        break;
                    case '.':
                        point.emplace_back(sf::CircleShape());
                        point.back().setRadius(Size.x / 8);
                        point.back().setPosition(sidebar + i * Size.x + Size.x / 2 - Size.x / 8,
                                                 j * Size.y + Size.y / 2 - Size.x / 8);
                        break;
                    case 'o':
                        powerup.emplace_back(sf::CircleShape());
                        powerup.back().setRadius(Size.x / 4);
                        powerup.back().setPosition(sidebar + i * Size.x + Size.x / 2 - Size.x / 4,
                                                   j * Size.y + Size.y / 2 - Size.x / 4);
                        break;
                    case '+':
                        point.emplace_back(sf::CircleShape());
                        point.back().setRadius(Size.x / 8);
                        point.back().setPosition(sidebar + i * Size.x + Size.x / 2 - Size.x / 8,
                                                 j * Size.y + Size.y / 2 - Size.x / 8);
                        break;
                    case 'P':
                        Pac_pos = sf::Vector2f(sidebar + i * Size.x, j * Size.y);
                        break;
                    case '=':
                        gate.setSize(Size2);
                        gate.setPosition(sidebar + i * Size.x, j * Size.y);
                        gate.setTexture(&Resources::bridge);
                        break;
                    default:
                        if (map_sketch[j][i] != ' ') {
                            Ghost_pos.emplace_back(sf::Vector2f());
                            Ghost_pos.back() = sf::Vector2f(sidebar + i * Size.x, j * Size.y);
                        }
                        break;
                }
            }
        }
    }
    sf::Vector2f getPac_pos(){
        return Pac_pos;
    }
    std::vector<sf::CircleShape>& getPoints(){
        return point;
    }
    std::vector<sf::CircleShape>& getPowerup(){
        return powerup;
    }
    bool update(sf::Vector2f Pos){
        bool eatPower=false;
        for (int i = 0; i < static_cast<int>(point.size()); i++) {
            if(point[i].getGlobalBounds().contains(Pos)) {
                point.erase(point.begin() + i);
            }
        }
        for (int i = 0; i < static_cast<int>(powerup.size()); i++) {
            if(powerup[i].getGlobalBounds().contains(Pos)) {
                eatPower=true;
                powerup.erase(powerup.begin() + i);
            }
        }
        return eatPower;
    }
    std::vector<sf::Vector2f> getGhost_pos(){
        return Ghost_pos;
    }
    void drawTo(sf::RenderWindow &window) {
        window.draw(background);
        for(const auto& w:wall)
            window.draw(w);
        for(const auto& p:point)
            window.draw(p);
        for(const auto& o:powerup)
            window.draw(o);
        window.draw(gate);
    }
};
#endif //OOP_MAP_H
