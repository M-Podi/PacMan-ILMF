#include "Player.h"

Player::Player(const std::string &name, int scor, time_t time) : name(name), bestScore(scor), timePlayed(time) {}

Player::~Player() {
    std::cout << "Am apelat deconstructorul \n";
}

Player::Player(const Player &other) : name(other.name), bestScore(other.bestScore), timePlayed(other.timePlayed) {}

[[maybe_unused]] void Player::setBestScore(int score) {
    this->bestScore = score;
}

int Player::getBestScore() const {
    return bestScore;
}

[[maybe_unused]] void Player::setName(const std::string &pName) {
    this->name = pName;
    std::string encrypt="";
    for(int i=0;i<name.length();i++){
        if(isupper(name[i])){
            encrypt+=(name[i]-'A'+13)%26+'A';
        }else if(islower(name[i])){
            encrypt+=(name[i]-'a'+13)%26+'a';
        }
        else
            encrypt+=name[i];
    }
    this->enc_name=encrypt;
}
[[maybe_unused]] void Player::setEnc(const std::string &encName) {
    this->enc_name = encName;
}

std::string Player::getEnc() const {
    return enc_name;
}

std::string Player::getName() const {
    return name;
}

[[maybe_unused]] void Player::setTime(time_t time) {
    this->timePlayed = time;
}

time_t Player::getTime() const {
    return timePlayed;
}

std::ostream &operator<<(std::ostream &os, const Player &other) {
    os << other.getName() << " a obtinut " << other.getBestScore() << " puncte in " << other.getTime() << " secunde\n";
    return os;
}