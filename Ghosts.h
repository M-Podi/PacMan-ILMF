//
// Created by Matei on 12/21/2022.
//

#ifndef OOP_GHOSTS_H
#define OOP_GHOSTS_H
#include "Entity.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cfloat>
class Ghosts:public Entity {
private:
    int id=0,timer=0;
    bool scared=false;
public:
    Ghosts()=default;
    Ghosts(float x, float y,sf::Texture &color,int id):Entity(x,y,color,2),id(id){};
    void handleMovement(const std::vector<std::string> &map_sketch,sf::Vector2f destPos) override;
    Entity* clone() const override { return new Ghosts(*this); }
    //void setScared(bool scared) override;
    int getTimer()const;
};

#endif //OOP_GHOSTS_H
