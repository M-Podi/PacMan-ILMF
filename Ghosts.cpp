#include "Ghosts.h"

const int ROW = 21, COL = 21;
typedef std::pair<int, int> Pair;
typedef std::pair<double, Pair> pPair;

struct cell {
    int parent_i, parent_j;
    double f, g, h;
};


bool isUnBlocked(std::vector<std::string> map_sketch, int row, int col) {
    return (map_sketch[row][col] != '#');
}

bool isDestination(int row, int col, Pair dest) {
    return (row == dest.first && col == dest.second);
}

double calculateHValue(int row, int col, Pair dest) {
    return (double)abs(row - dest.first) + abs(col - dest.second);
}

void tracePath(cell cellDetails[][COL], Pair dest) {
    printf("\nThe Path is ");
    int row = dest.first, col = dest.second;
    std::stack<Pair> Path;
    while (row != cellDetails[row][col].parent_i || col != cellDetails[row][col].parent_j) {
        Path.push({row, col});
        int temp_row = cellDetails[row][col].parent_i, temp_col = cellDetails[row][col].parent_j;
        row = temp_row, col = temp_col;
    }
    Path.push({row, col});
    while (!Path.empty()) {
        Pair p = Path.top(); Path.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }
}
void aStarSearch(std::vector<std::string> map_sketch, Pair src, Pair dest) {

    if (!isUnBlocked(map_sketch, src.first, src.second)) {
        printf("Source is blocked\n");
        return;
    }
    if (!isUnBlocked(map_sketch, dest.first, dest.second)){
        printf("destination is blocked\n");
        return;
    }
    if (isDestination(src.first, src.second, dest)) {
        printf("We are already at the destination\n");
        return;
    }

    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    cell cellDetails[ROW][COL];
    std::priority_queue<pPair, std::vector<pPair>, std::greater<pPair>> openList;

    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++) {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }

    int i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;
    openList.push({0.0, {i, j}});

    while (!openList.empty()) {
        pPair p = openList.top();
        openList.pop();
        i = p.second.first, j = p.second.second;
        closedList[i][j] = true;

        double gNew, hNew, fNew;

        if (isUnBlocked(map_sketch, i - 1, j)) {
            if (isDestination(i - 1, j, dest)) {
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                tracePath(cellDetails, dest);
                return;
            }
            else if (!closedList[i - 1][j]) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i - 1, j, dest);
                fNew = gNew + hNew;
                if (cellDetails[i - 1][j].f > fNew) {
                    openList.push({fNew, {i - 1, j}});
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }

        if (isUnBlocked(map_sketch, i + 1, j)) {
            if (isDestination(i + 1, j, dest)) {
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                tracePath(cellDetails, dest);
                return;
            }
            else if (!closedList[i + 1][j]) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i + 1, j, dest);
                fNew = gNew + hNew;
                if (cellDetails[i + 1][j].f > fNew) {
                    openList.push({fNew, {i + 1, j}});
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }

        if (isUnBlocked(map_sketch, i, j - 1)) {
            if (isDestination(i, j - 1, dest)) {
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                tracePath(cellDetails, dest);
                return;
            }
            else if (!closedList[i][j - 1]) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j - 1, dest);
                fNew = gNew + hNew;
                if (cellDetails[i][j - 1].f > fNew) {
                    openList.push({fNew, {i, j - 1}});
                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }

        if (isUnBlocked(map_sketch, i, j + 1)) {
            if (isDestination(i, j + 1, dest)) {
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                tracePath(cellDetails, dest);
                return;
            }
            else if (!closedList[i][j + 1]) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j + 1, dest);
                fNew = gNew + hNew;
                if (cellDetails[i][j + 1].f > fNew) {
                    openList.push({fNew, {i, j + 1}});
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }
    }
    printf("Failed to find the Destination Cell\n");
    return;
}
void Ghosts::handleMovement(const std::vector<std::string> &map_sketch,sf::Vector2f relPos) {
    sf::Vector2f Pos,relPos2;
    Pos=this->GetPosition();
    relPos2.x=static_cast<int>(Pos.x/rect.getSize().x)-8;
    relPos2.y=static_cast<int>(Pos.y/rect.getSize().x);
    Pair src = std::make_pair(relPos2.y, relPos2.x);
    Pair dest = std::make_pair(relPos.y, relPos.x);
    aStarSearch(map_sketch, src, dest);
}
