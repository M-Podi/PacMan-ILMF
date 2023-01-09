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
    time_t timePlayed=0;
    std::vector<int> pastScores;
public:
    Player()=default;
    explicit Player(std::string &name, time_t time = 0);

    Player(const Player &player);

    ~Player()=default;


    //void setName(const std::string &name);



    uint32_t getEnc() const;



    //time_t getTime() const;


    Player& operator = (Player other) {
        swap(*this,other);
        return *this;
    }
    friend void swap(Player &first,Player &second){
        using std::swap;
        swap(first.name,second.name);
        swap(first.pastScores,second.pastScores);
        swap(first.enc_name,second.enc_name);
        swap(first.timePlayed,second.timePlayed);
    }

};

#endif
