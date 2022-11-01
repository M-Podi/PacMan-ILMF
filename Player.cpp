#include "Player.h"

Player::Player(std::string name, int scor, time_t time): name(name), bestScore(scor), timePlayed(time) {}

Player::~Player() {
    std::cout << "Am apelat deconstructorul \n";
}
Player::Player(const Player& other): name(other.name), bestScore(other.bestScore), timePlayed(other.timePlayed) { }

[[maybe_unused]] void Player::setBestScore(int score) {
    this->bestScore = score;
}
int Player::getBestScore() const {
    return bestScore;
}
[[maybe_unused]] void Player::setName(const std::string& pName) {
    this->name = pName;
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
std::ostream& operator<<(std::ostream& os,const Player& other) {
    os << other.getName() << " a obtinut " << other.getBestScore() << " puncte in " << other.getTime() << " secunde\n";
    return os;
}