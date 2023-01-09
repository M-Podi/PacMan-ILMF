#include "Player.h"


Player::Player(std::string &name, time_t time) : name(name), timePlayed(time) {
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


Player::Player(const Player &other) : name(other.name), enc_name(other.enc_name), pastScores(other.pastScores), timePlayed(other.timePlayed){}



uint32_t Player::getEnc() const {
    return enc_name;
}




