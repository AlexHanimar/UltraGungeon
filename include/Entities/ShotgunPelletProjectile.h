#pragma once

#include <Entities/Projectile.h>

class ShotgunPelletProjectile : public Projectile {
private:
    qreal lifeTime;
    qreal maxLifeTime = 1.0;
public:
    ShotgunPelletProjectile(QPointF pos, QPointF dir);
    void update(qreal deltaT) override;
};