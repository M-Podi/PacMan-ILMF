#ifndef OOP_MAP_H
#define OOP_MAP_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include <vector>
class Map {
    std::vector<sf::RectangleShape> wall;
    std::vector<sf::CircleShape> point,powerup;
    sf::RectangleShape gate;
    sf::Vector2f Size,Pac_pos,Size2,Start_Pos;
    std::vector<sf::Vector2f> Ghost_pos;
    int sidebar;
public:
    Map()=default;
    void Innit(const int Map_Height,const int Screen_Height,const int Screen_Width,std::vector<std::string> map_sketch){
        Size.x=Screen_Height/Map_Height;
        Size.y=Screen_Height/Map_Height;
        Size2.x=Size.x;
        Size2.y=Size.y/3;
        sidebar=(Screen_Width-Size.x*map_sketch.size())/2;
        for(int i = 0;i < map_sketch.size();i++){
            for(int j = 0; j < map_sketch[i].size();j++){
                switch(map_sketch[j][i]){
                    case '#':
                        wall.emplace_back(sf::RectangleShape());
                        wall.back().setSize(Size);
                        wall.back().setPosition(sidebar+i*Size.x,j*Size.y);
                        wall.back().setFillColor(sf::Color::Cyan);
                        break;
                    case '.':
                        point.emplace_back(sf::CircleShape());
                        point.back().setRadius(Size.x/8);
                        point.back().setPosition(sidebar+i*Size.x+Size.x/2-Size.x/8,j*Size.y+Size.y/2-Size.x/8);
                        break;
                    case 'o':
                        powerup.emplace_back(sf::CircleShape());
                        powerup.back().setRadius(Size.x/4);
                        powerup.back().setPosition(sidebar+i*Size.x+Size.x/2-Size.x/4,j*Size.y+Size.y/2-Size.x/4);
                        break;
                    case 'P':
                        Pac_pos=sf::Vector2f(sidebar+i*Size.x,j*Size.y);
                        break;
                    case '=':
                        gate.setSize(Size2);
                        gate.setPosition(sidebar+i*Size.x,j*Size.y);
                        gate.setFillColor(sf::Color::Cyan);
                    default:
                        if(map_sketch[j][i]>=0&&map_sketch[i][j]<=9){
                            Ghost_pos.emplace_back(sf::Vector2f());
                            Ghost_pos.back()=sf::Vector2f(sidebar+i*Size.x,j*Size.y);}
                        break;
                }
            }
        }
    }
    sf::Vector2f getPac_pos(){
        return Pac_pos;
    }
    std::vector<sf::RectangleShape> getWalls(){
        return wall;
    }
    [[maybe_unused]] sf::Vector2f getGhost_pos(int i){
        return Ghost_pos[i];
    }
    void drawTo(sf::RenderWindow &window) {
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
