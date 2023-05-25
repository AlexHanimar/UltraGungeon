#pragma once

#include <Entities/MovableEntity.h>
#include <Entities/Teams.h>

class Projectile : public MovableEntity {
private:
    int state;
    qreal damage;
    TEAM team;
public:
    enum STATE {
        DEFAULT = 0,
        DESTROYED = 1
    };
    using MovableEntity::MovableEntity;
    void setDamage(qreal _damage);
    [[nodiscard("Projectile::getDamage() unused")]] qreal getDamage() const;
    void setTeam(TEAM _team);
    [[nodiscard("Projectile::getTeam() unused")]] TEAM getTeam() const;
    void setState(int _state);
    [[nodiscard("Projectile::getState() unused")]] int getState() const;

    virtual ~Projectile() noexcept = default;
};

Projectile* pistol1(QPointF pos, QPointF dir);
Projectile* pistol2(QPointF pos, QPointF dir);
std::vector<Projectile*> shotgun1(QPointF pos, QPointF dir);
Projectile* shotgun2(QPointF pos, QPointF dir);
Projectile* railgun1(QPointF pos, QPointF dir);
Projectile* railgun2(QPointF pos, QPointF dir);

Projectile* andreBall(QPointF pos, QPointF dir);