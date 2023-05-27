#include <Entities/BlueRailcannonHitscan.h>

BlueRailcannonHitscan::BlueRailcannonHitscan(QPointF pos, QPointF dir) : Hitscan(10.0, 1000000, pos, dir, 0.5, TEAM::PLAYER) {}