#pragma once

#include <Entities/Projectile.h>

class AndreBallProjectile : public Projectile {
public:
    AndreBallProjectile(QPointF pos, QPointF dir);
    enum STATE {
        DEFAULT = 0,
        DESTROYED = 2
    };
    void setState(int _state) override;
};