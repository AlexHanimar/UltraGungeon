#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <algorithm>

enum class ROOM_TYPE {
    ENTRANCE,
    EXIT,
    COMMON,
    NONE
};

class MapGenerator {
private:
    std::mt19937 gen;
public:
    MapGenerator(void) = delete;
    explicit MapGenerator(unsigned int seed);
    std::vector<std::vector<ROOM_TYPE>> generateMap(size_t h, size_t w);
};
