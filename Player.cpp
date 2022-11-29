#include "Player.h"

Player::Player(const std::string &name, int scor, time_t time) : name(name), bestScore(scor), timePlayed(time) {}

Player::~Player() {
    std::cout << "Am apelat destructorul \n";
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
    /*std::string encrypt="";
    for(unsigned long i=0; i<name.length(); i++){
        if(isalpha(name[i]))
            encrypt+=(std::tolower(name[i]) - 'a' + 13) % 26 + 'a';
        else
            encrypt += name[i];
    }
    this->enc_name=encrypt;*/
    const uint32_t Polynomial = 0x04C11DB7;
    uint32_t crc = ~0u;
    //unsigned char* current = (unsigned char*) pName;
    for(const char &it:pName)
    {
        //crc ^= *current++;
        crc ^= it;
        for (unsigned int j = 0; j < 8; j++)
            crc = (crc >> 1) ^ (-int(crc & 1) & Polynomial);
    }
    this->enc_name=~crc; // same as crc ^ 0xFFFFFFFF
}

uint32_t Player::getEnc() const {
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

