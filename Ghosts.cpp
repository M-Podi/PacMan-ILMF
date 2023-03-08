#include "Ghosts.h"

bool isUnBlocked(std::vector<std::string> map_sketch, int row, int col) {
    return (map_sketch[row][col] != '#');
}


void Ghosts::handleMovement(const std::vector<std::string> &map_sketch,sf::Vector2f destPos) {


    sf::Vector2f Pos, relPos2;
    double up, down, left, right;
    Pos = this->GetPosition();
    if(Pos.x/rect.getSize().x-8<1)
        relPos2.x=2;
    else
        relPos2.x=static_cast<int>((Pos.x/rect.getSize().x))-8;
    relPos2.y = static_cast<int>(Pos.y / rect.getSize().x);
//    if (this->scared) {
//        switch (this->id % 4) {
//            case 0:
//                dest = std::make_pair(destPos.y, destPos.x);
//                break;
//            case 1:
//                dest = std::make_pair(destPos.y, destPos.x);
//                break;
//            case 2:
//                dest = std::make_pair(destPos.y, destPos.x);
//                break;
//            default:
//                dest = std::make_pair(destPos.y, destPos.x);
//                break;
//        }
//    } else {
//        switch (this->id % 4) {
//            case 0:
//                dest = std::make_pair(destPos.y, destPos.x);
//                break;
//            case 1:
//                dest = std::make_pair(destPos.y, destPos.x);
//                break;
//            case 2:
//                dest = std::make_pair(destPos.y, destPos.x);
//                break;
//            default:
//                dest = std::make_pair(destPos.y, destPos.x);
//                break;
//        }
//    }

    down = std::sqrt((Pos.x - destPos.x) * (Pos.x - destPos.x) +
                   (Pos.y - destPos.y + remaining) * (Pos.y - destPos.y + remaining));
    up = std::sqrt((Pos.x - destPos.x) * (Pos.x - destPos.x) +
                     (Pos.y - destPos.y - remaining) * (Pos.y - destPos.y - remaining));
    left = std::sqrt((Pos.x - destPos.x - remaining) * (Pos.x - destPos.x - remaining) +
                     (Pos.y - destPos.y) * (Pos.y - destPos.y));
    right = std::sqrt((Pos.x - destPos.x + remaining) * (Pos.x - destPos.x + remaining) +
                      (Pos.y - destPos.y) * (Pos.y - destPos.y));

    if (up < down && up < left && up < right && isUnBlocked(map_sketch,relPos2.y-1,relPos2.x))
        currentDirection = UP;
    else if (down < left && down < right && isUnBlocked(map_sketch,relPos2.y+1,relPos2.x))
        currentDirection = DOWN;
    else if (left < right && isUnBlocked(map_sketch,relPos2.y,relPos2.x-1))
        currentDirection = LEFT;
    else
        currentDirection = RIGHT;
    remaining = rect.getSize().y;
    std::cout<<id<<" "<<up<<" "<<down<<" "<<left<<" "<<right<<std::endl;
//    else
//        currentDirection = NONE;
//    if (src.second < p.second) {
//        currentDirection = RIGHT;
//    } else if (src.second > p.second) {
//        currentDirection = LEFT;
//    } else if (src.first < p.first) {
//        currentDirection = DOWN;
//    } else if (src.first > p.first) {
//        currentDirection = UP;
//    } else {
//        currentDirection = previousDirection;
//    }
    if (canMove(relPos2 + directions[currentDirection], map_sketch)) {
        //std::cout<<"Can move\n";
        if (currentDirection == previousDirection || previousDirection == NONE) {
            currentDirection = NONE;
            remaining = 0;
            previousDirection = NONE;
        } else
            currentDirection = NONE;
        //currentDirection = previousDirection;
    }
}