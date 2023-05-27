#include <Entities/PistolHitscan.h>

PistolHitscan::PistolHitscan(QPointF pos, QPointF dir) : Hitscan(1.0, 1, pos, dir, 0.1, TEAM::PLAYER) {}