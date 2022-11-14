#include<iostream>
#include<vector>
#include <cctype>
class Player {
private:
    std::string name,enc_name;
    int bestScore;
    time_t timePlayed;
public:
    //Player();
    explicit Player(const std::string &name, int score = 0, time_t time = 0);

    Player(const Player &player);

    ~Player();

    void setBestScore(int score);

    int getBestScore() const;

    void setName(const std::string &name);

    std::string getName() const;

    std::string getEnc() const;

    void setTime(time_t time);

    time_t getTime() const;

    friend std::ostream &operator<<(std::ostream &os, const Player &other);

    Player &operator=(const Player &other) = default;


};

std::ostream &operator<<(std::ostream &os, const Player &player1);