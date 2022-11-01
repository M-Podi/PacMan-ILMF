#include<iostream>

class Player {
private:
    std::string name;
    int bestScore;
    time_t timePlayed;
public:
    //Player();
    Player(std::string name="Nume", int score = 0, time_t time = 0);
    Player(const Player& player);
    ~Player();
    void setBestScore(int score);
    int getBestScore() const;

    void setName(const std::string& name);
    std::string getName() const;

    void setTime(time_t time);
    time_t getTime() const;

    friend std::ostream& operator << (std::ostream& os, const Player& other);
    Player& operator = (const Player& other) = default;
};
std::ostream& operator<<(std::ostream& os,const Player& player1);