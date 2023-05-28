#pragma once

#include <Entities/Projectile.h>

class ParryProjectile : public Projectile {
public:
    ParryProjectile(QPointF pos, QPointF dir);
};