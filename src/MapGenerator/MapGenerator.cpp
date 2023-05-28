#include <MapGenerator/MapGenerator.h>
#include <iostream>

MapGenerator::MapGenerator(unsigned int seed)
        : gen(std::mt19937(seed)) {}

std::vector<std::vector<ROOM_TYPE>> MapGenerator::generateMap(size_t h, size_t w)
{
    const int baseCount = std::max(h, w);
    const int additionalCount = baseCount / 2;

    std::vector<std::vector<ROOM_TYPE>> res(h, std::vector<ROOM_TYPE>(w, ROOM_TYPE::NONE));
    int xSt = gen() % h, ySt = gen() % w;
    res[xSt][ySt] = ROOM_TYPE::ENTRANCE;
    int roomCnt = baseCount + (gen() % additionalCount);
    std::pair<int, int> curPos = { xSt, ySt };
    std::vector<std::pair<int, int>> allRooms;
    while (roomCnt) {
        size_t dir = gen() % 4;
        switch (dir) {
            case 0: // up
                if (curPos.first > 0)
                    curPos.first--;
                break;
            case 1: // down
                if (curPos.first + 1 < h)
                    curPos.first++;
                break;
            case 2: // left
                if (curPos.second > 0)
                    curPos.second--;
                break;
            case 3: // right
                if (curPos.second + 1 < w)
                    curPos.second++;
                break;
            default:
                break;
        }
        if (res[curPos.first][curPos.second] == ROOM_TYPE::NONE) {
            roomCnt--;
            res[curPos.first][curPos.second] = ROOM_TYPE::COMMON;
            allRooms.push_back(curPos);
        }
    }
    do {
        std::shuffle(allRooms.begin(), allRooms.end(), gen);
        curPos = *allRooms.begin();
        if (abs(curPos.first - xSt) + abs(curPos.second - ySt) < 2)
            continue;
        res[curPos.first][curPos.second] = ROOM_TYPE::EXIT;
        break;
    } while (true);

    /*for(int i = 0;i < h;i++) {
        for(int j = 0;j < w;j++) {
            switch(res[i][j]) {
                case ROOM_TYPE::NONE:
                    std::cout << 0;
                    break;
                case ROOM_TYPE::COMMON:
                case ROOM_TYPE::ENTRANCE:
                case ROOM_TYPE::EXIT:
                    std::cout << 1;
                    break;
            }
        }
        std::cout << std::endl;
    }*/

    return res;
}
