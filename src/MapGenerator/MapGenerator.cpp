#include <MapGenerator/MapGenerator.h>

MapGenerator::MapGenerator(unsigned int seed)
        : gen(std::mt19937(seed))
{}

std::vector<std::vector<ROOM_TYPE>> MapGenerator::generateMap(size_t h, size_t w)
{
    const int baseCount = 10;
    const int additionalCount = 5;

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
    return res;
}
