#pragma once

#include <vector>
#include <random>

enum class BLOCK_TYPE {
    WALL,
    DOOR,
    NONE
};

enum CONNECT {
    UP = 1,
    DOWN = 2,
    LEFT = 4,
    RIGHT = 8
};

class RoomGenerator {
public:
    std::vector<std::vector<BLOCK_TYPE>> generateRoom(size_t h, size_t w, int mask);
};