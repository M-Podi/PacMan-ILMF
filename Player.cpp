#include "Player.h"


Player::Player(std::string &name, int scor, time_t time) : name(name), bestScore(scor), timePlayed(time) {
    if(name.empty())
        throw InvalidNameError("Name cannot be empty");

    uint32_t previousCrc32 = 0;
    const uint32_t Polynomial = 0xEDB88320;
    uint32_t crc = ~previousCrc32;

    auto current = name.c_str();

    auto s = name.size();
    while (s--)
    {
        crc ^= *current++;
        for (unsigned int j = 0; j < 8; j++)
            if (crc & 1)
                crc = (crc >> 1) ^ Polynomial;
            else
                crc =  crc >> 1;
    }
    enc_name=~crc;
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




