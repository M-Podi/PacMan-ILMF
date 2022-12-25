#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include "Exceptions.h"
#include<iostream>
#include<vector>
#include <cctype>
#include<cstring>
class Player {
private:
    std::string name=" ";
    uint32_t enc_name=0;
    int bestScore=0;
    time_t timePlayed=0;
public:
    Player()=default;
    explicit Player(const std::string &name, int score = 0, time_t time = 0);

    Player(const Player &player);

    ~Player();


    //void setName(const std::string &name);



    uint32_t getEnc() const;



    //time_t getTime() const;


    Player& operator = (Player other) {
        std::swap(this->name, other.name);
        std::swap(this->enc_name, other.enc_name);
        std::swap(this->bestScore,other.bestScore);
        std::swap(this->timePlayed,other.timePlayed);
        return *this;
    }


};

#endif
