#include "Player.h"


Player::Player(const std::string &name, int scor, time_t time) : name(name), bestScore(scor), timePlayed(time) {
    if(name.empty())
        throw InvalidNameError("Name cannot be empty");
    const uint32_t Polynomial = 0x04C11DB7;
    uint32_t crc = ~0u;
    for(const char &it:name)
    {
        crc ^= std::tolower(it);
        for (unsigned int j = 0; j < 8; j++)
            crc = (crc >> 1) ^ (-(int32_t(crc & 1) & Polynomial));
    }
    enc_name=~crc;
}

Player::~Player() {
    std::cout << "Am apelat destructorul \n";
}

Player::Player(const Player &other) : name(other.name), enc_name(other.enc_name), bestScore(other.bestScore), timePlayed(other.timePlayed){}




//[[maybe_unused]] void Player::setName(const std::string &pName) {
//    this->name = pName;
//    const uint32_t Polynomial = 0x04C11DB7;
//    uint32_t crc = ~0u;
//    for(const char &it:pName)
//    {
//        crc ^= std::tolower(it);
//        for (unsigned int j = 0; j < 8; j++)
//            crc = (crc >> 1) ^ (-(int32_t(crc & 1) & Polynomial));
//    }
//    this->enc_name=~crc;
//}

uint32_t Player::getEnc() const {
    return enc_name;
}




