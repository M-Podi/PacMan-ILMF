#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include<iostream>
#include<vector>
#include <cctype>
#include<string.h>
class Player {
private:
    std::string name;
    uint32_t enc_name;
    int bestScore;
    time_t timePlayed;
public:
    Player()=default;
    explicit Player(const std::string &name, int score = 0, time_t time = 0);

    Player(const Player &player);

    ~Player();

    void setBestScore(int score);

    int getBestScore() const;

    void setName(const std::string &name);

    std::string getName() const;

    uint32_t getEnc() const;

    void setTime(time_t time);

    time_t getTime() const;



    Player &operator=(const Player &other) = default;

};

#endif
