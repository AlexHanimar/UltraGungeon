#pragma once

#include <Entities/Projectile.h>

class ShotgunPelletProjectile : public Projectile {
public:
    ShotgunPelletProjectile(QPointF pos, QPointF dir);
};