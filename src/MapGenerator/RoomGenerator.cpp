#include <MapGenerator/RoomGenerator.h>
#include <stdexcept>

std::vector<std::vector<BLOCK_TYPE>> RoomGenerator::generateRoom(size_t h, size_t w, int mask)
{
    if (h & 1)
        throw std::runtime_error("incorrect room size");
    if (w & 1)
        throw std::runtime_error("incorrect room size");
    if(h == 0 || w == 0)
        throw std::runtime_error("incorrect room size");
    std::vector<std::vector<BLOCK_TYPE>> res(h, std::vector<BLOCK_TYPE>(w, BLOCK_TYPE::NONE));
    for (size_t i = 0; i < h; i++)
        res[i][0] = res[i][w - 1] = BLOCK_TYPE::WALL;
    for (size_t i = 0; i < w; i++)
        res[0][i] = res[h - 1][i] = BLOCK_TYPE::WALL;
    if (mask & CONNECT::UP)
        res[0][w / 2] = res[0][w / 2 - 1] = BLOCK_TYPE::DOOR;
    if (mask & CONNECT::DOWN)
        res[h - 1][w / 2] = res[h - 1][w / 2 - 1] = BLOCK_TYPE::DOOR;
    if (mask & CONNECT::LEFT)
        res[h / 2][0] = res[h / 2 - 1][0] = BLOCK_TYPE::DOOR;
    if (mask & CONNECT::RIGHT)
        res[h / 2][w - 1] = res[h / 2 - 1][w - 1] = BLOCK_TYPE::DOOR;
    return res;
}
