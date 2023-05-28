#include <Entities/BlueRailgunHitscan.h>

BlueRailgunHitscan::BlueRailgunHitscan(QPointF pos, QPointF dir) : Hitscan(10.0, 1000000, pos, dir, 0.5, TEAM::PLAYER) {}